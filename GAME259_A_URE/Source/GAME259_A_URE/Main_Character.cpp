// Copyright Epic Games, Inc. All Rights Reserved.

#include "Main_Character.h"
#include "Main_PlayerController.h"
#include "CTF_GameMode.h"
#include "CTF_GameState.h"
#include "Kismet/GameplayStatics.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "Animation/AnimMontage.h"
#include "Net/UnrealNetwork.h"
#include "Sound/SoundBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Public/CombatStatusComponent.h"
#include "Public/CombatStatusActor.h"
#include "Public/CombatAmmoContainerComponent.h"
#include "Public/StrafeComponent.h"
#include "Public/BallRepulsorComponent.h"
#include "CTF_PlayerState.h"

//////////////////////////////////////////////////////////////////////////
// AThirdPersonMPCharacter
// AMain_Character

AMain_Character::AMain_Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
	//GetCharacterMovement()->bUseControllerDesiredRotation = true;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	//Component to determine the ball spawn location
	ballSpawnLocation = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ballSpawnLocation"));
	ballSpawnLocation->SetupAttachment(RootComponent);
	ballSpawnLocation->bHiddenInGame = true;

	//Initialize the player's Health
	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;
	velPercentage = 1.0f;
	bReplicates = true;
	CombatStatusComp = CreateDefaultSubobject<UCombatStatusComponent>(TEXT("CombatStatus"));
	StrafeAbility = CreateDefaultSubobject<UStrafeComponent>(TEXT("StrafeAbility"));
	BallRepulsorAbility = CreateDefaultSubobject<UBallRepulsorComponent>(TEXT("BallRepulsorAbility"));
	//Audio Components
	FireAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("FireAudio"));
	WalkingSound = CreateDefaultSubobject<USoundBase>(TEXT("WalkingAudio"));
	TakeDamageSound = CreateDefaultSubobject<USoundBase>(TEXT("TakeDamageAudio"));
	ShootingSound = CreateDefaultSubobject<USoundBase>(TEXT("ShootingAudio"));
	PickupSound = CreateDefaultSubobject<USoundBase>(TEXT("ShootingAudio"));
	
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
	
	//Define the ammo containers
	CombatAmmoContainerComp0 = CreateDefaultSubobject<UCombatAmmoContainerComponent>(TEXT("AmmoContainer0"));
	CombatAmmoContainerComp1 = CreateDefaultSubobject<UCombatAmmoContainerComponent>(TEXT("AmmoContainer1"));
	CombatAmmoContainerComp2 = CreateDefaultSubobject<UCombatAmmoContainerComponent>(TEXT("AmmoContainer2"));

	//Container used to store the default balls
	CombatAmmoContainerComp0->ballInContainer = BallDefault;
	CombatAmmoContainerComp0->ballNum = 5;
	CombatAmmoContainerComp0->maxBallNum = 5;

	//Container used to store the fire balls
	CombatAmmoContainerComp1->ballInContainer = BallFire;
	CombatAmmoContainerComp1->ballNum = 0;
	CombatAmmoContainerComp1->maxBallNum = 3;

	//Container used to store the ice balls
	CombatAmmoContainerComp2->ballInContainer = BallIce;
	CombatAmmoContainerComp2->ballNum = 0;
	CombatAmmoContainerComp2->maxBallNum = 4;

	//Enables whether  to lower the power of impulse
	lowerPower = false;

	//Disables shooting if true, used for delaying the attack
	delayAttack = false;

	//Enables character debugger
	debug = false;

	//How much time to delay the next attack after each throw
	attackDelay = 1.5f;

	//Stores the currently equipped ball
	currentBall = BallDefault;

	// The amount to offset the ball spawner by
	ballSpawnOffset = 100.0f;

	//The initial impulse
	impulse = 7000.0f;

	//Impulse of the default ball
	impulseDef = 10000.0f;
	//Impulse of the fire ball
	impulseFire = 10000.0f;
	//Impulse of the ice ball
	impulseIce = 10000.0f;

	//Stores the initial impulse of each ball type
	impulseDefOrig = impulseDef;
	impulseFireOrig = impulseFire;
	impulseIceOrig = impulseIce;

	powerOn = true;
}

//////////////////////////////////////////////////////////////////////////
// Input

void AMain_Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMain_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMain_Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMain_Character::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMain_Character::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AMain_Character::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AMain_Character::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AMain_Character::OnResetVR);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMain_Character::Attack);

	//Controls the ball's power (impulse)
	//PlayerInputComponent->BindAction("PowerDown", IE_Pressed, this, &AMain_Character::LowPower);
	//PlayerInputComponent->BindAction("PowerUp", IE_Pressed, this, &AMain_Character::FullPower);

	PlayerInputComponent->BindAction("PowerDown", IE_Pressed, this, &AMain_Character::BallIndexIncrease);
	PlayerInputComponent->BindAction("PowerUp", IE_Pressed, this, &AMain_Character::BallIndexDecrease);

	//Combat Abilities binding
	PlayerInputComponent->BindAction("BallRepulsor", IE_Pressed, this, &AMain_Character::ActivateBallRepulsor_Server);
	PlayerInputComponent->BindAction("Strafe", IE_Pressed, this, &AMain_Character::ActivateStrafe);

	PlayerInputComponent->BindAction("Inventory1", IE_Pressed, this, &AMain_Character::SetToBallType0);
	PlayerInputComponent->BindAction("Inventory2", IE_Pressed, this, &AMain_Character::SetToBallType1);
	PlayerInputComponent->BindAction("Inventory3", IE_Pressed, this, &AMain_Character::SetToBallType2);
}


void AMain_Character::OnResetVR()
{
	// If ThirdPersonMP is added to a project via 'Add Feature' in the Unreal Editor the dependency on HeadMountedDisplay in ThirdPersonMP.Build.cs is not automatically propagated
	// and a linker error will result.
	// You will need to either:
	//		Add "HeadMountedDisplay" to [YourProject].Build.cs PublicDependencyModuleNames in order to build successfully (appropriate if supporting VR).
	// or:
	//		Comment or delete the call to ResetOrientationAndPosition below (appropriate if not supporting VR)
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AMain_Character::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void AMain_Character::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void  AMain_Character::BeginPlay()
{
	Super::BeginPlay();
	AmmoBallSlot.Empty();
	AmmoBallSlot.Add(CombatAmmoContainerComp0);
	AmmoBallSlot.Add(CombatAmmoContainerComp1);
	AmmoBallSlot.Add(CombatAmmoContainerComp2);
	FireAudio->Stop();
}

// https://docs.unrealengine.com/5.0/en-US/API/Runtime/Engine/Engine/ENetRole/
// https://docs.unrealengine.com/5.0/en-US/actor-role-and-remoterole-in-unreal-engine/
/*FString GetEnumText(ENetRole BallRole)
{
	switch (BallRole)
	{
	case ROLE_None:
		return "ROLE_None";
	case ROLE_SimulatedProxy:
		return "ROLE_SimulatedProxy";
	case ROLE_AutonomousProxy:
		return "ROLE_AutonomousProxy";
	case ROLE_Authority:
		return "ROLE_Authority";
	case ROLE_MAX:
		return "WTF is ROLE_Max";
	default:
		return "hello";
	}
}*/

void AMain_Character::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Checks for NetRole
	//DrawDebugString(GetWorld(), FVector(0,0,100), GetEnumText(GetLocalRole()), this, FColor::Black, DeltaSeconds);

	
}

void AMain_Character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMain_Character, CurrentHealth);
	DOREPLIFETIME(AMain_Character, BallTable);
}


void AMain_Character::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMain_Character::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());

}

void AMain_Character::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		
		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value * velPercentage); // custom defined velocity should be in effect
	}
}

void AMain_Character::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value * velPercentage);
	}
}

//////////////////////////////////////////////////////////////////////////

void AMain_Character::OnHealthUpdate()
{
	if (IsLocallyControlled()){
		// Updates Health Bar
		HealthUpdate.Broadcast(); // Added
	}
	if (HasAuthority()){
		if (CurrentHealth <= 0)
		{
			FString deathMessage = FString::Printf(TEXT("You have been killed."));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, deathMessage);
			Die();
			// Calls Death Event to Remove HUD
			DeathEvent();
		}
	}
}

void AMain_Character::OnRep_CurrentHealth() // Added replication to CurrentHealth
{
	OnHealthUpdate();
}

void AMain_Character::SetCurrentHealth(float healthValue, AController* EventInstigator, AActor* DamageCauser)
{
	//Prevent current health to go above max health
	if (HasAuthority())
	{
		CurrentHealth = FMath::Clamp(healthValue, 0.f, MaxHealth);

		OnHealthUpdate();
		if (CurrentHealth <= 0)
		{
			//Display dying message when health reaches 0
			FString killerName = "";

			//If the controller exists for this player
			if (GetController()) {
				//If some controller is responsible for the damage
				if (EventInstigator) {
					ACTF_PlayerState* playerState = EventInstigator->GetPlayerState<ACTF_PlayerState>();
					killerName = playerState->GetPlayerName();
				}
				else {
					//Check which actor causes the damage if there's no controller responsible for the damage
					if (DamageCauser) {
						//If it is killed by self, it is a falling damage
						if (DamageCauser == this) {
							killerName = "Falling Damage";
						}
						//If it is killed by something else, it should be a combat status
						else {
							killerName = DamageCauser->GetFName().ToString();
							ACombatStatusActor* combatStatus = (ACombatStatusActor*)DamageCauser;
							if (combatStatus) {
								killerName = combatStatus->getName().ToString();
							}
						}
					}
					else { 
						killerName = "Unknown";
					}
				}
				KillerUpdate.Broadcast(killerName);
			}
		}
	}
}


float AMain_Character::TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float damageApplied = 0.0f;
	bool checkDamage = true;

	//If the player has a controller, check damage
	if (GetController()) {
		//Check if damageinstigator exists
		if (EventInstigator != nullptr) {
			//If the damage is dealt by self, ignore it
			if (EventInstigator == GetController()) {
				checkDamage = false;
			}
			else {
				//Check player's team
				ACTF_PlayerState* damageCauserPlayerState = Cast<ACTF_PlayerState>(EventInstigator->PlayerState);
				ACTF_PlayerState* playerState = Cast<ACTF_PlayerState>(this->GetPlayerState());
				if (playerState && damageCauserPlayerState) {
					if (playerState->team == damageCauserPlayerState->team) {
						checkDamage = false;
					}
				}
			}
		}
	}
	else {
		checkDamage = false;
	}
	
	if (checkDamage) {
		if (CurrentHealth > 0.0f) {
			damageApplied = CurrentHealth - DamageTaken;
			// Changes the CurrentHealth variable
			SetCurrentHealth(damageApplied, EventInstigator, DamageCauser);
			FDamageEvent damageEvent = DamageEvent;
			if ((FOvertimeDamageEvent*)&damageEvent == nullptr) {
			}
			PlaySound_Server(TakeDamageSound, GetActorLocation());
			//UGameplayStatics::PlaySoundAtLocation(GetWorld(), TakeDamageAudio->Sound, GetActorLocation());
			//TakeDamageAudio->Play();
		}
	}
	return damageApplied;
}

void AMain_Character::Attack()
{
	//If the ball has ammo, fire
	if (GetAmmoContainer(currentBall)->ballNum > 0)
	{
		//Check if the option to adjust power is on
		if (powerOn) {
			//Checks for the default ball
			if (currentBall == CombatAmmoContainerComp0->ballInContainer)
			{
				if (lowerPower == true)
				{
					//Lowers the impulse of the default ball
					impulseDef = impulseDef * 0.25f;
				}
				else
				{
					impulseDef = impulseDefOrig;
				}

				impulse = impulseDef;
			}
			//Checks for the fire ball
			if (currentBall == CombatAmmoContainerComp1->ballInContainer)
			{
				if (lowerPower == true)
				{
					//Lowers the impulse of the fire ball
					impulseFire = impulseFire * 0.25f;
				}
				else
				{
					impulseFire = impulseFireOrig;
				}

				impulse = impulseFire;
			}
			//Checks for the ice ball
			if (currentBall == CombatAmmoContainerComp2->ballInContainer)
			{
				if (lowerPower == true)
				{
					//Lowers the impulse of the ice ball
					impulseIce = impulseIce * 0.25f;
				}
				else
				{
					impulseIce = impulseIceOrig;
				}

				impulse = impulseIce;
			}
		}

		//if the player has not attacked recently 
		if (delayAttack == false) {
			TSubclassOf<class ABallActor> BallActorClass = nullptr;
			switch (currentBall) {
				case BallDefault:
					BallActorClass = BallDefaultClass;
					break;
				case BallFire:
					BallActorClass = BallFireClass;
					break;
				case BallIce:
					BallActorClass = BallIceClass;
					break;
				default:
					break;
			}
			SpawnBallBP_Server(ballSpawnLocation->GetComponentLocation() + ballSpawnLocation->GetComponentRotation().Vector() * ballSpawnOffset, FollowCamera->GetComponentRotation(),
				FollowCamera->GetForwardVector() * impulse, BallActorClass);

			//Delay the next attack
			delayAttack = true;
			//Start the delay timer
			GetWorldTimerManager().SetTimer(DelayHandle, this, &AMain_Character::DelayAttack, attackDelay);
			//Take away one ball
			GetAmmoContainer(currentBall)->MinusNum(1);
			UCombatAmmoContainerComponent* ammoContainer = GetAmmoContainer(currentBall);
			AmmoUpdate.Broadcast(AmmoBallSlot.Find(ammoContainer), ammoContainer->ballNum);
			DelayAttackUpdate.Broadcast();
			PlaySound_Server(ShootingSound, GetActorLocation());

			
			if (throwAnim) {
				PlayAnimation_Server(throwAnim);
			}
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No ammo"));
	}

	if (debug == true) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, FString::Printf(TEXT("Current Actor Location: X:%f | Y:%f"), this->GetActorLocation().X, this->GetActorLocation().Y));
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, TEXT(">Attack Pressed") );
		//Displays the amount time before the player can attack again
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("Time until next attack: %f"), GetWorldTimerManager().GetTimerRemaining(DelayHandle)));;	
	}
}

void AMain_Character::SpawnBallBP_NetMulticast_Implementation(FVector location, FRotator rotation, FVector impulse_, TSubclassOf<class ABallActor> ballActorClass_) {
	FActorSpawnParameters ballSpawnInfo;
	ballSpawnInfo.Owner = this;
	ballSpawnInfo.Instigator = this;
	ballSpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ABallActor* ballActorBase = GetWorld()->SpawnActor<ABallActor>(ballActorClass_, location, rotation, ballSpawnInfo);
	//Checks if the ball actor being used as a base to spawn the ball exists
	if (ballActorBase) {
		//Throws the ball
		ballActorBase->ApplyImpulse(impulse_);
		ballActorBase->IsLethal = true;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("BallActor not found"));
	}
}

void AMain_Character::SpawnBallBP_Server_Implementation(FVector location, FRotator rotation, FVector impulse_, TSubclassOf<class ABallActor> ballActorClass_){
	SpawnBallBP_NetMulticast_Implementation(location, rotation, impulse_, ballActorClass_);
}


void AMain_Character::PlaySound_Multicast_Implementation(USoundBase* sound_, FVector location_){
	UGameplayStatics::SpawnSoundAttached(sound_, GetRootComponent());
}



void AMain_Character::PlaySound_Server_Implementation(USoundBase* sound_, FVector location_){
	PlaySound_Multicast(sound_, location_);
}


bool AMain_Character::PlaySound_Server_Validate(USoundBase* sound_, FVector location_)
{
	return true;
}

//Function to set whether to lower the impulse
void AMain_Character::LowPower()
{
	lowerPower = true;
	if (debug == true) {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Magenta, TEXT(">Power Halfed") );
	}
	PowerUpdate.Broadcast(1);
	
}

//Function to set whether to use maximum impulse
void AMain_Character::FullPower()
{
	lowerPower = false;
	if (debug == true) {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Magenta, TEXT(">Power Full") );
	}
	PowerUpdate.Broadcast(0);
}

//Function used to set the attack delay
void AMain_Character::DelayAttack()
{
	delayAttack = false;
	//Clears the delay timer
	GetWorldTimerManager().ClearTimer(DelayHandle);
}

void AMain_Character::ManualAddBall()
{
	AmmoBallSlot[0]->ManualAddNum();
	if (debug == true) {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Magenta, TEXT(">Ball Added Manually") );
	}
	
}

void AMain_Character::ManualMinusBall()
{
	AmmoBallSlot[0]->ManualMinusNum();
	//AmmoBallSlot[0]->MinusNum(1);
	if (debug == true) {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Magenta, TEXT(">Ball Removed Manually") );
	}
	
}

void AMain_Character::On_Destroy() {
	BallRepulsorAbility->OnDestroy();
	CombatStatusComp->RemoveCombatStatusList_Server();
	PlaySound_Server(DeadSound, GetActorLocation());
}

void AMain_Character::PlayAnimation_Multicast_Implementation(UAnimMontage* throwAnim_)
{
	PlayAnimMontage(throwAnim_);
}

void AMain_Character::PlayAnimation_Server_Implementation(UAnimMontage* throwAnim_)
{
	PlayAnimation_Multicast(throwAnim_);
}

bool AMain_Character::PlayAnimation_Server_Validate(UAnimMontage* throwAnim_)
{
	return true;
}

void AMain_Character::Die()
{
	//if (ROLE_Authority)
	//{
		On_Destroy();

	//}
	//Currently used to handle dropping flag
	if (ACTF_GameState* GS = Cast<ACTF_GameState>(GetWorld()->GetGameState())) {
		AMain_PlayerController* playerController = GetController<AMain_PlayerController>();
		GS->PlayerDied(playerController);
	}
	MultiDie();
	AGameModeBase* GM = GetWorld()->GetAuthGameMode();
	if (ACTF_GameMode* GameMode = Cast <ACTF_GameMode>(GM))
	{
		GameMode->Respawn(GetController());
	}
	if (GetController()) {
		APlayerController* playerController = GetController<APlayerController>();
		DisableInput(playerController);
	}
	//Start our destroy timer to remove actor
	GetWorld()->GetTimerManager().SetTimer(DestroyHandle, this, &AMain_Character::CallDestroy, 10.0f, false);
	//}
}

void AMain_Character::CallDestroy()
{
	if (HasAuthority())
	{
		Destroy();
	}
}


bool AMain_Character::MultiDie_Validate()
{
	return true;
}

void AMain_Character::MultiDie_Implementation()
{
	GetMovementComponent()->Velocity = FVector(0.0f, 0.0f, 0.0f);
	GetCapsuleComponent()->DestroyComponent();
	this->GetCharacterMovement();
	this->GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	this->GetMesh()->SetAllBodiesSimulatePhysics(true);
}

void AMain_Character::FellOutOfWorld(const UDamageType& dmgType)
{
	TakeDamage(100.0f, FDamageEvent(), nullptr, this);
}

void AMain_Character::AddCombatStatus(FName statusName_, AController* EventInstigator) {

	if (HasAuthority()) {
		if (GetController()) {
			if (CurrentHealth > 0.0f) {
				//Check if damageinstigator exists
				if (EventInstigator != nullptr) {
					ACTF_PlayerState* damageCauserPlayerState = Cast<ACTF_PlayerState>(EventInstigator->PlayerState);
					ACTF_PlayerState* playerState = Cast<ACTF_PlayerState>(this->GetPlayerState());
					if (playerState && damageCauserPlayerState) {
						if (playerState->team != damageCauserPlayerState->team) {
							CombatStatusComp->AddCombatStatus_Server(statusName_);
						}
					}
				}
				else {
					CombatStatusComp->AddCombatStatus_Server(statusName_);
				}
			}
		}
	}
}


void AMain_Character::AddBallAmmo(TEnumAsByte<EBallType> ballType, int ballNum) {

	int index = 0;
	//Check which index should be added
	switch (ballType){

	case BallDefault:
			index = AmmoBallSlot.Find(CombatAmmoContainerComp0);
			break;
		case BallFire:
			index = AmmoBallSlot.Find(CombatAmmoContainerComp1);
			break;
		case BallIce:
			index = AmmoBallSlot.Find(CombatAmmoContainerComp2);
			break;
		default:
			break;
	}
	//Add ammo to the AmmoBallSlot and broadcast the delegate
	if (AmmoBallSlot[index]) {
		AmmoBallSlot[index]->AddNum(ballNum);
		AmmoUpdate.Broadcast(index, AmmoBallSlot[index]->ballNum);
		PlaySound_Server(PickupSound, GetActorLocation());
		currentBall = ballType;
	}
}

FString AMain_Character::GetNameOfActor(){
	return GetName();
}




void AMain_Character::ActivateBallRepulsor_Server_Implementation() {
	ActivateBallRepulsor_Multicast();
}

void AMain_Character::ActivateBallRepulsor_Multicast_Implementation()
{
	if (BallRepulsorAbility->ActivateAbility()) {
		if (BallRepulsorAbility->AbilitySound) {
			PlaySound_Server(BallRepulsorAbility->AbilitySound, GetActorLocation());
		}
		AbilityCooldownUpdate.Broadcast(1, BallRepulsorAbility->getCooldown());
	}
}

void AMain_Character::ActivateStrafe() {

	if (StrafeAbility->ActivateAbility()) {
		if (StrafeAbility->AbilitySound) {
			PlaySound_Server(StrafeAbility->AbilitySound, GetActorLocation());
		}
		AbilityCooldownUpdate.Broadcast(3, StrafeAbility->getCooldown());
	}

}

UCombatAmmoContainerComponent* AMain_Character::GetAmmoContainer(TEnumAsByte<EBallType> ballType_)
{
	for (UCombatAmmoContainerComponent* container : AmmoBallSlot) {
		if (container->ballInContainer == ballType_) {
			return container;
		}
	}

	return nullptr;
}

void AMain_Character::SetToBallType0() {
	currentBall = CombatAmmoContainerComp0->ballInContainer;
	AmmoUpdate.Broadcast(0, CombatAmmoContainerComp0->ballNum);
}

void AMain_Character::SetToBallType1() {
	currentBall = CombatAmmoContainerComp1->ballInContainer;
	AmmoUpdate.Broadcast(1, CombatAmmoContainerComp1->ballNum);
}

void AMain_Character::SetToBallType2() {
	currentBall = CombatAmmoContainerComp2->ballInContainer;
	AmmoUpdate.Broadcast(2, CombatAmmoContainerComp2->ballNum);
}

void AMain_Character::BallIndexIncrease() {
	int index = AmmoBallSlot.Find(GetAmmoContainer(currentBall));
	index++;
	if (index >= AmmoBallSlot.Num()) {
		index = 0;
	}
	currentBall = AmmoBallSlot[index]->ballInContainer;
	AmmoUpdate.Broadcast(index, AmmoBallSlot[index]->ballNum);
}

void AMain_Character::BallIndexDecrease() {
	int index = AmmoBallSlot.Find(GetAmmoContainer(currentBall));
	index--;
	if (index < 0) {
		index = AmmoBallSlot.Num() - 1;
	}
	currentBall = AmmoBallSlot[index]->ballInContainer;
	AmmoUpdate.Broadcast(index, AmmoBallSlot[index]->ballNum);
}