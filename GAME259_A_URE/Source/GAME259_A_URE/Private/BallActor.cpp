// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"

// Sets default values
ABallActor::ABallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setsup the sphere component
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	//Institutes the sphere component to the root component
	RootComponent = SphereComp;
	//With a radius of 40
	SphereComp->InitSphereRadius(40.0f);
	//Sets the default collision profile to "Projectile" profile
	SphereComp->SetCollisionProfileName(TEXT("Projectile"));
	
	//Sets the mesh's model in code (not the best practice)
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereMesh->SetupAttachment(RootComponent);

	//Sets the default model to use
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		SphereMesh->SetStaticMesh(SphereVisualAsset.Object);
		//Moves the mesh down
		SphereMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -35.0f));
		//Scales the mesh to 70% of its size
		SphereMesh->SetWorldScale3D(FVector(0.7f)); 
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> SphereMaterialAsset(TEXT("/Game/Materials/BallMat.BallMat"));
	if (SphereMaterialAsset.Succeeded())
	{
		SphereMesh->SetMaterial(0, SphereMaterialAsset.Object);
	}

	//Simulates physics
	SphereMesh->SetSimulatePhysics(true);
	
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
}

// Called when the game starts or when spawned
void ABallActor::BeginPlay()
{
	Super::BeginPlay();

	//Sets the timer to countdown at start
	GetWorldTimerManager().SetTimer(TimeHandle, this, &ABallActor::DestroyTimerUp, DestroyTimer);
	
}

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (Debug == true)
	{
		if (HasStatus == true)
		{
			//Displays the type of status on the actor
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, TEXT("Status Applyed: " + Status));
		}
		//Displays the Velocity of the actor
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, FString::Printf(TEXT("Current Actor Velocity: %f"), SphereComp->GetPhysicsLinearVelocity().Size()));
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
	if (IsLethal == true)
	{
		//Broadcasts the time to add message with the amount of time needed
		MessageDamage.Broadcast(DamageToDeal);

		//If status is enabled broadcast it
		if (HasStatus == true)
		{
			//Broadcasts the the status effect
			MessageStatus.Broadcast(Status);
		}
		
		//Destroys the actor that collides with this object
		OtherActor->Destroy();
		//Destroys this game actor
		this->Destroy();	
	}
	
}
