// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatStatusComponent.h"
#include "GameFramework/Actor.h"
#include "CombatStatusActor.h"
#include "DamageOverTimeActor.h"
#include "ReduceSpeedActor.h"
#include "GAME259_A_URE/Main_Character.h"


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
	AMain_Character* player = (AMain_Character*)GetOwner();
	if (player && player->GetCurrentHealth() > 0.0f)
	{
		//Check if datatable exist
		if (CombatStatusTable) {
			FCombatStatus* combatStatusInfo = CombatStatusTable->FindRow<FCombatStatus>(rowName_, TEXT("test"), true);
			//Check if row name exist
			if (combatStatusInfo) {

				UE_LOG(LogTemp, Warning, TEXT("Database Row found"));
				ACombatStatusActor* statusActor = existCombatStatus(rowName_);
				//if the status already exist in the list, refresh time
				if (statusActor) {
					statusActor->refreshTime();
					UE_LOG(LogTemp, Warning, TEXT("Refresh time"));
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
					//Spawn actor according to the status type, and add it to the lists
					switch (combatStatusInfo->statusClass) {
					case DamageOverTime:
					{
						UE_LOG(LogTemp, Warning, TEXT("DamageOverTime Type"));
						statusActor = GetWorld()->SpawnActor<ADamageOverTimeActor>(
							ADamageOverTimeActor::StaticClass(),
							spawnLocation, rotation, ActorSpawnParams);
						break;
					}

					case ReduceSpeed:
					{
						UE_LOG(LogTemp, Warning, TEXT("ReduceSpeed Type"));
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
}

void UCombatStatusComponent::AddCombatStatus_Server_Implementation(FName rowName_)
{
	AddCombatStatus(rowName_);
}

bool UCombatStatusComponent::AddCombatStatus_Server_Validate(FName rowName_)
{
	return true;
}

void UCombatStatusComponent::RemoveCombatStatus(ACombatStatusActor* statusActor){
	int i = combatStatusList.Find(statusActor);
	combatStatusList.RemoveAt(i);
}

void UCombatStatusComponent::RemoveCombatStatusList_Multicast_Implementation()
{
	for (ACombatStatusActor* status : combatStatusList) {
		UE_LOG(LogTemp, Warning, TEXT("Removing status list"));
		status->Destroy();
	}
	combatStatusList.Empty();
}

void UCombatStatusComponent::RemoveCombatStatusList_Server_Implementation() {
	RemoveCombatStatusList_Multicast();
}


ACombatStatusActor* UCombatStatusComponent::existCombatStatus(FName statusName_) {

	for (ACombatStatusActor* status : combatStatusList) {
		if (status->getName() == statusName_) {
			return status;
		}
	}

	return nullptr;
}