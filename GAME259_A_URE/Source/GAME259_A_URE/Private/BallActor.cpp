// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "../Main_Character.h"

// Sets default values
ABallActor::ABallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//NetPriority = 3;
	//NetUpdateFrequency = 1000;
	//
	//bAlwaysRelevant = true;
	bNetLoadOnClient = true;
	bReplicates = true;
	//bStaticMeshReplicateMovement = true;
	
	//Setsup the sphere component
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	//Institutes the sphere component to the root component
	RootComponent = SphereComp;
	//With a radius of 40
	SphereComp->InitSphereRadius(40.0f);
	//SphereComp->BodyInstance.SetCollisionProfileName(TEXT("BallCollision"));
	SphereComp->SetCollisionProfileName(TEXT("BallCollisionOverlap"));
	SphereComp->bHiddenInGame = false;
	//SphereComp->SetIsReplicated(true);
	//Simulates physics
	SphereComp->SetSimulatePhysics(true);

	//Sets the mesh's model in code (not the best practice)
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereMesh->SetupAttachment(RootComponent);

	//SphereMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component"));
	//SphereMovement->UpdatedComponent = SphereComp;
	//SphereMovement->InitialSpeed = 3000.0f;
	//SphereMovement->bRotationFollowsVelocity = true;
	//SphereMovement->bShouldBounce = true;
	//Moves the mesh down

	SphereMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -35.0f));
	//Scales the mesh to 70% of its size
	SphereMesh->SetWorldScale3D(FVector(0.7f)); 


	//Amount of time to add
	DamageToDeal = 5;

	//The time it takes before this actor is destroyed
	DestroyTimer = 15.0f;

	//Set whether to enable debug options
	Debug = false;

	//Determines if the actor has a status effect or not
	HasStatus = false;

	//The type of status to apply
	Status = "None";

	//Lethal setup
	IsLethal = true;

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
	//SphereComp->OnComponentHit.AddDynamic(this, &ABallActor::OnBlock);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ABallActor::BeginOverlap);
}

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//If the ball reaches a certain velocity, the ball becomes lethal
	float velocity = SphereComp->GetPhysicsLinearVelocity().Size();
	if (velocity > lethalVelocity) {
		IsLethal = true;
	}
	else {
		IsLethal = false;
	}
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

//An overlap function
void ABallActor::OnBlock(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) {
		//Check if the ball is overlapping with the character
		if (OtherActor->IsA(AMain_Character::StaticClass())) {

			AMain_Character* playerCharacter = (AMain_Character*)OtherActor;

			if (IsLethal)
			{
				//Broadcasts the time to add message with the amount of time needed
				MessageDamage.Broadcast(DamageToDeal);
				TSubclassOf<UDamageType> DamageType = UDamageType::StaticClass();
				AController* DamageCauserController = nullptr;

				if (GetInstigator()) {
					DamageCauserController = GetInstigator()->GetController();
				}

				playerCharacter->TakeDamage(DamageToDeal, FDamageEvent(DamageType), DamageCauserController, this);
				//If status is enabled broadcast it
				if (Status != "None") {
					UE_LOG(LogTemp, Warning, TEXT("Adding combat status"));

					playerCharacter->AddCombatStatus(Status);
				}

				if (HasStatus == true)
				{
					//Broadcasts the the status effect
					//MessageStatus.Broadcast(Status);
				}

			}
			else if (!IsLethal){
				//Add ball ammo then destroy the character
				playerCharacter->AddBallAmmo(ballType, 1);
				this->Destroy();	
			}
		}
	}
}


void ABallActor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, FString::Printf(TEXT("Overlap Lethal: %s"), IsLethal ? TEXT("True") : TEXT("False")));

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) {
		//Check if the ball is overlapping with the character
		if (OtherActor->IsA(AMain_Character::StaticClass())) {

			AMain_Character* playerCharacter = (AMain_Character*)OtherActor;

			if (IsLethal)
			{
				//Broadcasts the time to add message with the amount of time needed
				MessageDamage.Broadcast(DamageToDeal);
				TSubclassOf<UDamageType> DamageType = UDamageType::StaticClass();
				AController* DamageCauserController = nullptr;

				if (GetInstigator()) {
					DamageCauserController = GetInstigator()->GetController();
				}

				playerCharacter->TakeDamage(DamageToDeal, FDamageEvent(DamageType), DamageCauserController, this);
				//If status is enabled broadcast it
				if (Status != "None") {
					UE_LOG(LogTemp, Warning, TEXT("Adding combat status"));

					playerCharacter->AddCombatStatus(Status);
				}

				if (HasStatus == true)
				{
					//Broadcasts the the status effect
					//MessageStatus.Broadcast(Status);
				}

			}
			else if (!IsLethal) {
				//Add ball ammo then destroy the character
				playerCharacter->AddBallAmmo(ballType, 1);
				this->Destroy();
			}
		}
	}
}
void ABallActor::ApplyForce(float force_) {
	//Apply am opposite force if the parameter is negative
	FVector velocityVec = SphereComp->GetPhysicsLinearVelocity();
	if (velocityVec.Size() <= 0) {
		SphereComp->AddForce(GetActorForwardVector() * 3000.0f * force_);
	}
	SphereComp->AddForce(GetActorForwardVector() * 3000.0f * force_);
}

void ABallActor::ApplyImpulse(FVector impulse_) {
	SphereComp->AddImpulse(impulse_, FName("None"), true);
	//SphereMovement->AddForce(impulse_ * 100.0f);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("Impulse %f %f %f"), impulse_.X, impulse_.Y, impulse_.Z));;

}

void ABallActor::setValue(UStaticMesh* sphereMesh_, UMaterial* sphereMaterial_,
	float damageToDeal_, FName combatStatus_, TEnumAsByte<EBallType> ballType_, bool isLethal_) {

	if (sphereMesh_) {
		SphereMesh->SetStaticMesh(sphereMesh_);
		SphereMesh->SetMaterial(0, sphereMaterial_);
	}
	//IsLethal = isLethal_;
	DamageToDeal = damageToDeal_;
	Status = combatStatus_;
	ballType = ballType_;
	UE_LOG(LogTemp, Warning, TEXT("Combat status: %s"), *Status.ToString());

}

