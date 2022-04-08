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


}


// Called every frame
void UCombatStatusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCombatStatusComponent::AddCombatStatus_Implementation(FName rowName_)
{
	//Check if datatable exist
	if (CombatStatusTable) {
		FCombatStatus* combatStatusInfo = CombatStatusTable->FindRow<FCombatStatus>(rowName_, TEXT("test"), true);
		//Check if row name exist
		if (combatStatusInfo) {

			ACombatStatusActor* statusActor = existCombatStatus(rowName_);
			//if the status already exist in the list, refresh time
			if (statusActor) {
				statusActor->refreshTime();

			}
			else {
				//Create all the variables that will be used to create the actor
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.Owner = this->GetOwner();
				float durationTime = combatStatusInfo->durationTime;
				float effectAmount = combatStatusInfo->effectAmount;
				UParticleSystem* particleEffect = combatStatusInfo->particleEffect;
				FString description = combatStatusInfo->description;
				UTexture2D* icon = combatStatusInfo->icon;
				FVector spawnLocation = GetOwner()->GetActorLocation();
				FRotator rotation = GetOwner()->GetActorRotation();
				//Spawn actor according to the status type, and add it to the list
				switch (combatStatusInfo->statusClass) {
				case DamageOverTime:
				{
					statusActor = GetWorld()->SpawnActor<ADamageOverTimeActor>(
						ADamageOverTimeActor::StaticClass(),
						spawnLocation, rotation, ActorSpawnParams);
					break;
				}

				case ReduceSpeed:
				{
					statusActor = GetWorld()->SpawnActor<AReduceSpeedActor>(
						AReduceSpeedActor::StaticClass(),
						spawnLocation, rotation, ActorSpawnParams);
					break;
				}

				default:
					break;
				}
				//Set the value for the actor, and activate it
				statusActor->setValue(rowName_, durationTime, effectAmount, particleEffect, description, icon);
				combatStatusList.Add(statusActor);
				//Attach to Actor
				statusActor->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
				//Setup the delegates when the combatStatus is destroyed
				statusActor->OnCombStatusRemove.AddDynamic(this, &UCombatStatusComponent::RemoveCombatStatus);
			}
			OnCombStatusAdd.Broadcast(statusActor->getName());
			
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

void UCombatStatusComponent::RemoveCombatStatusList() {
	for (ACombatStatusActor* status : combatStatusList) {
		status->Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Destroying combat status"));
	}


	combatStatusList.Empty();
}


ACombatStatusActor* UCombatStatusComponent::existCombatStatus(FName statusName_) {

	for (ACombatStatusActor* status : combatStatusList) {
		if (status->getName() == statusName_) {
			return status;
		}
	}

	return nullptr;
}