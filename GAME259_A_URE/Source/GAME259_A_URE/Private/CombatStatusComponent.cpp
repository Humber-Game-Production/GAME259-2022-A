// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatStatusComponent.h"
#include "GameFramework/Actor.h"
#include "CombatStatusActor.h"
#include "DamageOverTimeActor.h"
#include "ReduceSpeedActor.h"


// Sets default values for this component's properties
UCombatStatusComponent::UCombatStatusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	// ...
}


// Called when the game starts
void UCombatStatusComponent::BeginPlay()
{
	Super::BeginPlay();
	//Setup the delegates when the combatStatus is destroyed

}


// Called every frame
void UCombatStatusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCombatStatusComponent::AddCombatStatus(FName rowName_)
{
	//Check if datatable exist
	if (CombatStatusTable) {
		FCombatStatus* combatStatusInfo = CombatStatusTable->FindRow<FCombatStatus>(rowName_, TEXT("test"), true);
		//Check if row name exist
		if (combatStatusInfo) {
			UE_LOG(LogTemp, Warning, TEXT("Database Row found"));
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.Owner = this->GetOwner();
			float durationTime = combatStatusInfo->durationTime;
			float effectAmount = combatStatusInfo->effectAmount;
			UParticleSystem* particleEffect = combatStatusInfo->particleEffect;
			FVector spawnLocation = GetOwner()->GetActorLocation();
			FRotator rotation = GetOwner()->GetActorRotation();
			UE_LOG(LogTemp, Warning, TEXT("ActorLocation: %s"), *spawnLocation.ToString());

			//Spawn actor according to the status type, and add it to the list
			switch (combatStatusInfo->statusType) {
				case DamageOverTime:
				{
			
					UE_LOG(LogTemp, Warning, TEXT("DamageOverTime Type"));
					ACombatStatusActor* statusActor = GetWorld()->SpawnActor<ADamageOverTimeActor>(
						ADamageOverTimeActor::StaticClass(),
						spawnLocation, rotation, ActorSpawnParams);
					//Set the value for the actor, and activate it
					statusActor->setValue(rowName_, durationTime, effectAmount, particleEffect);
					combatStatusList.Add(statusActor);
					//Attach to Actor
					statusActor->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
					statusActor->OnCombStatusRemove.AddDynamic(this, &UCombatStatusComponent::RemoveCombatStatus);
					break;
				}

				case ReduceSpeed:
				{
					UE_LOG(LogTemp, Warning, TEXT("ReduceSpeed Type"));
					ACombatStatusActor* statusActor = GetWorld()->SpawnActor<AReduceSpeedActor>(
						AReduceSpeedActor::StaticClass(),
						spawnLocation, rotation, ActorSpawnParams);
					//Set the value for the actor, and activate it
					statusActor->setValue(rowName_, durationTime, effectAmount, particleEffect);
					combatStatusList.Add(statusActor);
					break;

				}

				default:
					break;
			}
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Database Not Found"));
	}
}

void UCombatStatusComponent::RemoveCombatStatus(ACombatStatusActor* statusActor){
	int i = combatStatusList.Find(statusActor);
	combatStatusList.RemoveAt(i);

}

