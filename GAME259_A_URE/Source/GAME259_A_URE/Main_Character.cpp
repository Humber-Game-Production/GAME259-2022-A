// Copyright Epic Games, Inc. All Rights Reserved.

#include "Main_Character.h"
#include "CTF_GameMode.h"
#include "LineTrace.h"
#include "PlayerStats.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

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
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

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
	
	//Initialize the player's Health
	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;
	bReplicates = true;
	PlayerStatsComp = CreateDefaultSubobject<UPlayerStatsComponent>("PlayerStats");
	LineTraceComp = CreateDefaultSubobject<ULineTrace>("LineTrace");

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
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
		AddMovementInput(Direction, Value);
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
		AddMovementInput(Direction, Value);
	}
}

//////////////////////////////////////////////////////////////////////////

void AMain_Character::OnHealthUpdate()
{	
		//Display message to show current health
		//FString healthMessage = FString::Printf(TEXT("You now have %f health remaining."), CurrentHealth);
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);

		//Display dying message when health reaches 0
		if (CurrentHealth <= 0)
		{
			FString deathMessage = FString::Printf(TEXT("You have been killed."));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, deathMessage);
			//BroadCast character dead
			DeadUpdate.Broadcast();
		}

}

void AMain_Character::SetCurrentHealth(float healthValue)
{
	//Prevent current health to go above max health
	CurrentHealth = FMath::Clamp(healthValue, 0.f, MaxHealth);
	//Broadcast health changes
	HealthUpdate.Broadcast();
	//HealthUpdate.Broadcast(CurrentHealth);

	OnHealthUpdate();
	
}


float AMain_Character::TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float damageApplied = CurrentHealth - DamageTaken;
	SetCurrentHealth(damageApplied);
	return damageApplied;
}

void AMain_Character::Attack()
{
	ServerAttack();
}
/*
float AMain_Character::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	//Fix this Role < ROLE_Authority || PlayerStatsComp->GetHealth() < -0.0f
	if (GetLocalRole() < ROLE_Authority || PlayerStatsComp->GetHealth() <= 0.0f)
	{
		return 0.0f;
	}
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (ActualDamage > 0.0f)
	{
		PlayerStatsComp->LowerHealth(ActualDamage);
		if (PlayerStatsComp->GetHealth() <= 0.0f)
		{
			Die();
		}
	}
	return ActualDamage;
}
*/
bool AMain_Character::ServerAttack_Validate()
{
	return true;
}

void AMain_Character::ServerAttack_Implementation()
{
	if ((HasAuthority()))
	{

		TakeDamage(100.0f, FDamageEvent(), GetController(), this);

		/*FVector Start = GetMesh()->GetBoneLocation(FName("head"));
		FVector End = Start + FollowCamera->GetForwardVector() * 1500.0f;
		FHitResult HitResult = LineTraceComp->LineTraceSingle(Start, End, true);
		if (AActor* Actor = HitResult.GetActor())
		{
			if (AMain_Character* Player = Cast<AMain_Character>(Actor))
			{
				float TestDamage = 20.0f;

				TakeDamage(TestDamage, FDamageEvent(), GetController(), this);
			}
		}*/
	}
}

void AMain_Character::Die()
{
	if (HasAuthority())
	{
		MultiDie();
		AGameModeBase* GM = GetWorld()->GetAuthGameMode();
		if (ACTF_GameMode* GameMode = Cast <ACTF_GameMode>(GM))
		{
			GameMode->Respawn(GetController());
		}
		//Start our destroy timer to remove actor
		GetWorld()->GetTimerManager().SetTimer(DestroyHandle, this, &AMain_Character::CallDestroy, 10.0f, false);

	}
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
	GetCapsuleComponent()->DestroyComponent();
	this->GetCharacterMovement();
	this->GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	this->GetMesh()->SetAllBodiesSimulatePhysics(true);
}

void AMain_Character::FellOutOfWorld(const UDamageType& dmgType)
{
	Die();
}