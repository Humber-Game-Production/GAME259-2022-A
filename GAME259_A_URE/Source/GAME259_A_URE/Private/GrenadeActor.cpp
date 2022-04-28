// Fill out your copyright notice in the Description page of Project Settings.


#include "GrenadeActor.h"
#include "GrenadeComponent.h"
#include "../Main_Character.h"

// Sets default values
AGrenadeActor::AGrenadeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	//Institutes the sphere component to the root component
	RootComponent = SphereComp;
	//With a radius of 40
	SphereComp->InitSphereRadius(80.0f);
	//Sets the default collision profile to "Projectile" profile
	//SphereComp->SetCollisionProfileName(TEXT("Projectile"));
	SphereComp->SetCollisionProfileName(TEXT("BallCollision"));
	SphereComp->SetIsReplicated(true);
	SphereComp->bHiddenInGame = false;
	SphereComp->SetSimulatePhysics(true);

	//Sets the mesh's model in code (not the best practice)
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereMesh->SetupAttachment(RootComponent);
	//Simulates physics
	//Moves the mesh down
	//Scales the mesh to 70% of its size
	SphereMesh->SetWorldScale3D(FVector(0.7f));
	SphereMaterial = CreateDefaultSubobject<UMaterial>(TEXT("SphereMaterial"));

	//Amount of time to add
	DamageToDeal = 101;

	//The type of status to apply
	Status = "None";
}

void AGrenadeActor::BeginPlay()
{
	Super::BeginPlay();
	
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AGrenadeActor::BeginOverlap);
	//SphereMesh->SetMaterial(0, SphereMaterial);

}

void AGrenadeActor::ApplyImpulse(FVector impulse_)
{
	SphereComp->AddImpulse(impulse_, FName("None"), true);
}

void AGrenadeActor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) {
		//Check if the ball is overlapping with the character
		if (OtherActor->IsA(AMain_Character::StaticClass())) {

			AMain_Character* playerCharacter = (AMain_Character*)OtherActor;
			//Broadcasts the time to add message with the amount of time needed
			TSubclassOf<UDamageType> DamageType = UDamageType::StaticClass();
			//AController *DamageCauserController = GetOwner()->GetInstigatorController();
			playerCharacter->TakeDamage(DamageToDeal, FDamageEvent(DamageType), nullptr, this);
			this->Destroy();
		}
	}
}





