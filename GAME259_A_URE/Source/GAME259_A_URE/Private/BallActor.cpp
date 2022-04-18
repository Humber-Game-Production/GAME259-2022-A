// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"
#include "DrawDebugHelpers.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "../Main_Character.h"

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

// Sets default values
ABallActor::ABallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//NetPriority = 3;
	//NetUpdateFrequency = 1000;
	
	//AlwaysRelevant = true;
	bNetLoadOnClient = true; 
	bReplicates = true;

	//Setsup the sphere component
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	//Institutes the sphere component to the root component
	RootComponent = SphereComp;
	//With a radius of 40
	SphereComp->InitSphereRadius(40.0f);
	SphereComp->SetCollisionProfileName(TEXT("BallCollisionOverlap"));
	//Simulates physics
	SphereComp->SetSimulatePhysics(true);

	//Continuos Collision Detection
	SphereComp->SetUseCCD(true);
	
	//Sets the mesh's model in code (not the best practice)
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereMesh->SetupAttachment(RootComponent);

	//Moves the mesh down
	SphereMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -35.0f));
	//Scales the mesh to 70% of its size
	SphereMesh->SetWorldScale3D(FVector(0.7f)); 

	//Amount of time to add
	DamageToDeal = 5;

	//The time it takes before this actor is destroyed
	DestroyTimer = 5.0f;

	//Set whether to enable debug options
	Debug = false;

	//Determines if the actor has a status effect or not
	HasStatus = false;

	//The type of status to apply
	Status = "None";

	//Lethal setup
	IsLethal = false;

	lethalVelocity = 100.0f;

	ballType = BallDefault;
	SetReplicateMovement(true);
}

// Called when the game starts or when spawned
void ABallActor::BeginPlay()
{
	Super::BeginPlay();
	//Sets the timer to countdown at start
	GetWorldTimerManager().SetTimer(TimeHandle, this, &ABallActor::DestroyTimerUp, DestroyTimer);
	GetWorldTimerManager().SetTimer(LethalTimeHandle, this, &ABallActor::lethalOff, 1.0f);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ABallActor::BeginOverlap);
}

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Checks for NetRole
	//DrawDebugString(GetWorld(), FVector(0,0,100), GetEnumText(GetLocalRole()), this, FColor::Black, DeltaTime);

	//If the ball reaches a certain velocity, the ball becomes lethal
	//float velocity = SphereComp->GetPhysicsLinearVelocity().Size();
	//if (velocity > lethalVelocity) {
	//	IsLethal = true;
	//}
	//else {
	//	IsLethal = false;
	//}
	//if (Debug == true)
	//{
	//	if (HasStatus == true)
	//	{
	//		//Displays the type of status on the actor
	//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, TEXT("Status Applyed: " + Status.ToString()));
	//	}
	//	//Displays the Velocity of the actor
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, FString::Printf(TEXT("Current Actor Velocity: %f"), SphereComp->GetPhysicsLinearVelocity().Size()));
	//}
	
}

//Function used by the timer to determine what happens when the destroy timer is up
void ABallActor::DestroyTimerUp()
{
	if (Debug == true)
	{
		//Displays the actor has been destroyed
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Ball Actor Destroyed"));	
	}
	
	//Destroys this actor
	this->Destroy();
}

void ABallActor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)){
		//Check if the ball is overlapping with the character
		if (OtherActor->IsA(AMain_Character::StaticClass())){

			AMain_Character* playerCharacter = (AMain_Character*)OtherActor;
			AController* DamageCauserController = nullptr;
			if (GetInstigator()){
				DamageCauserController = GetInstigator()->GetController();
			}

			if (IsLethal)
			{
				//Broadcasts the time to add message with the amount of time needed
				MessageDamage.Broadcast(DamageToDeal);
				TSubclassOf<UDamageType> DamageType = UDamageType::StaticClass();
				playerCharacter->TakeDamage(DamageToDeal, FDamageEvent(DamageType), DamageCauserController, this);
				//Add Combat Status
				if (Status != "None"){
					if (playerCharacter) {
						playerCharacter->AddCombatStatus(Status, DamageCauserController);
					}
				}
				//if (playerCharacter->GetController()){
				//	if (DamageCauserController != playerCharacter->GetController()) {
				//		this->Destroy();
				//	}
				//}
			}
			else if (!IsLethal){
				//Add ball ammo then destroy the character
				playerCharacter->AddBallAmmo(ballType, 1);
				this->Destroy();
			}
		}
	}
}

void ABallActor::ApplyForce(float force_){
	//Apply am opposite force if the parameter is negative
	FVector velocityVec = SphereComp->GetPhysicsLinearVelocity();
	if (velocityVec.Size() <= 0) {
		SphereComp->AddForce(GetActorForwardVector() * 1500.0f * force_);
	}
	SphereComp->AddForce(GetActorForwardVector() * 1500.0f * force_);
}

void ABallActor::ApplyImpulse(FVector impulse_){
	SphereComp->AddImpulse(impulse_, FName("None"), true);
}

void ABallActor::setValue(UStaticMesh* sphereMesh_, UMaterial* sphereMaterial_,
	float damageToDeal_, FName combatStatus_, TEnumAsByte<EBallType> ballType_, bool isLethal_) {

	if (sphereMesh_) {
		SphereMesh->SetStaticMesh(sphereMesh_);
		SphereMesh->SetMaterial(0, sphereMaterial_);
	}
	IsLethal = isLethal_;
	DamageToDeal = damageToDeal_;
	Status = combatStatus_;
	ballType = ballType_;
}

void ABallActor::lethalOff() {
	IsLethal = false;
	GetWorldTimerManager().ClearTimer(LethalTimeHandle);
}



