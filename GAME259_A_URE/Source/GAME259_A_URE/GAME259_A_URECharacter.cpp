// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAME259_A_URECharacter.h"
#include "GAME259_A_UREGameMode.h"
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
// AGAME259_A_URECharacter

AGAME259_A_URECharacter::AGAME259_A_URECharacter()
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

	PlayerStatsComp = CreateDefaultSubobject<UPlayerStatsComponent>("PlayerStats");
	LineTraceComp = CreateDefaultSubobject<ULineTrace>("LineTrace");

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AGAME259_A_URECharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGAME259_A_URECharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGAME259_A_URECharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AGAME259_A_URECharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AGAME259_A_URECharacter::LookUpAtRate);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AGAME259_A_URECharacter::Attack);
}

void  AGAME259_A_URECharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AGAME259_A_URECharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AGAME259_A_URECharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AGAME259_A_URECharacter::MoveForward(float Value)
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

void AGAME259_A_URECharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
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

void AGAME259_A_URECharacter::Attack()
{
	TakeDamage(100.0f, FDamageEvent(), GetController(), this);
	
	/*
	FVector Start = GetMesh()->GetBoneLocation(FName("head"));
	FVector End = Start + FollowCamera->GetForwardVector() * 1500.0f;
	FHitResult HitResult = LineTraceComp->LineTraceSingle(Start, End, true);
	if (AActor* Actor = HitResult.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("HIT ACTOR: %s"), *Actor->GetName());
		if (AGAME259_A_URECharacter* Player = Cast<AGAME259_A_URECharacter>(Actor))
		{
			ServerAttack();
		}
	}*/
}

float AGAME259_A_URECharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
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
bool AGAME259_A_URECharacter::ServerAttack_Validate()
{
	return true;
}

void AGAME259_A_URECharacter::ServerAttack_Implementation()
{
	if ((HasAuthority()))
	{

		TakeDamage(100.0f, FDamageEvent(), GetController(), this);

		/*FVector Start = GetMesh()->GetBoneLocation(FName("head"));
		FVector End = Start + FollowCamera->GetForwardVector() * 1500.0f;
		FHitResult HitResult = LineTraceComp->LineTraceSingle(Start, End, true);
		if (AActor* Actor = HitResult.GetActor())
		{
			if (AGAME259_A_URECharacter* Player = Cast<AGAME259_A_URECharacter>(Actor))
			{
				float TestDamage = 20.0f;

				TakeDamage(TestDamage, FDamageEvent(), GetController(), this);
			}
		}*/
	}
}

void AGAME259_A_URECharacter::Die()
{
	if (HasAuthority())
	{
		MultiDie();
		AGameModeBase* GM = GetWorld()->GetAuthGameMode();
		if (AGAME259_A_UREGameMode* GameMode = Cast <AGAME259_A_UREGameMode>(GM))
		{
			GameMode->Respawn(GetController());
		}
		//Start our destroy timer to remove actor
		GetWorld()->GetTimerManager().SetTimer(DestroyHandle, this, &AGAME259_A_URECharacter::CallDestroy, 10.0f, false);

	}
}

void AGAME259_A_URECharacter::CallDestroy()
{
	if (HasAuthority())
	{
		Destroy();
	}
}
bool AGAME259_A_URECharacter::MultiDie_Validate()
{
	return true;
}

void AGAME259_A_URECharacter::MultiDie_Implementation()
{
	GetCapsuleComponent()->DestroyComponent();
	this->GetCharacterMovement();
	this->GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	this->GetMesh()->SetAllBodiesSimulatePhysics(true);
}