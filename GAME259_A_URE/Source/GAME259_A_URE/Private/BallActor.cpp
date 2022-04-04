// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"
#include "../Main_Character.h"

// Sets default values
ABallActor::ABallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bAlwaysRelevant = true;
	bNetLoadOnClient = true;
	bReplicates = true;
	
	//Setsup the sphere component
	
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	//Institutes the sphere component to the root component
	RootComponent = SphereComp;
	//With a radius of 40
	SphereComp->InitSphereRadius(40.0f);
	//Sets the default collision profile to "Projectile" profile
	//SphereComp->SetCollisionProfileName(TEXT("Projectile"));
	SphereComp->SetCollisionProfileName(TEXT("BallCollision"));
	SphereComp->SetIsReplicated(true);

	SphereComp->bHiddenInGame = false;
	
	//Sets the mesh's model in code (not the best practice)
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereMesh->SetupAttachment(RootComponent);
	//Simulates physics
	SphereComp->SetSimulatePhysics(true);
	//Moves the mesh down
	SphereMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -35.0f));
	//Scales the mesh to 70% of its size
	SphereMesh->SetWorldScale3D(FVector(0.7f)); 


	SphereMaterial = CreateDefaultSubobject<UMaterial>(TEXT("SphereMaterial"));
	
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
	IsLethal = false;

	lethalVelocity = 0.0f;

	ballType = BallDefault;
}

// Called when the game starts or when spawned
void ABallActor::BeginPlay()
{
	Super::BeginPlay();
	//Sets the timer to countdown at start
	GetWorldTimerManager().SetTimer(TimeHandle, this, &ABallActor::DestroyTimerUp, DestroyTimer);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ABallActor::BeginOverlap);
	//SphereMesh->SetMaterial(0, SphereMaterial);

}

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//If the ball reaches a certain velocity, the ball becomes lethal
	//float velocity = SphereMesh->GetPhysicsLinearVelocity().Size();
	//if (velocity > lethalVelocity) {
	//	IsLethal = true;
	//}
	//else {
	//	IsLethal = false;
	//}
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, FString::Printf(TEXT("Lethal: %s"), IsLethal ? TEXT("True") : TEXT("False")));

	if (Debug == true)
	{
		if (HasStatus == true)
		{
			//Displays the type of status on the actor
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, TEXT("Status Applyed: " + Status.ToString()));
		}
		//Displays the Velocity of the actor
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, FString::Printf(TEXT("Current Actor Velocity: %f"), SphereMesh->GetPhysicsLinearVelocity().Size()));
	}
	
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
void ABallActor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult )
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapping"));

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) {
		//Check if the ball is overlapping with the character
		if (OtherActor->IsA(AMain_Character::StaticClass())) {

			AMain_Character* playerCharacter = (AMain_Character*)OtherActor;

			if (IsLethal)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, FString::Printf(TEXT("Lethal: %s"), IsLethal ? TEXT("True") : TEXT("False")));
				//Broadcasts the time to add message with the amount of time needed
				MessageDamage.Broadcast(DamageToDeal);
				TSubclassOf<UDamageType> DamageType = UDamageType::StaticClass();
				//AController *DamageCauserController = GetOwner()->GetInstigatorController();
				playerCharacter->TakeDamage(DamageToDeal, FDamageEvent(DamageType), nullptr, this);
				//If status is enabled broadcast it
				if (Status != "None") {
					playerCharacter->AddCombatStatus(Status);
				}

				if (HasStatus == true)
				{
					//Broadcasts the the status effect
					//MessageStatus.Broadcast(Status);
				}

				//Destroys this game actor

			}
			else if (!IsLethal){
				//Add ball ammo then destroy the character
				playerCharacter->AddBallAmmo(ballType, 1);
				this->Destroy();	
			}
		}
	}





	

}