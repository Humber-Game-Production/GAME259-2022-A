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
			//Spawn actor according to the status type, and add it to the list
			switch (combatStatusInfo->statusType) {
				case DamageOverTime:
				{
					UE_LOG(LogTemp, Warning, TEXT("DamageOverTime Type"));
					ACombatStatusActor* statusActor = GetWorld()->SpawnActor<ADamageOverTimeActor>(ADamageOverTimeActor::StaticClass(),
						FVector(0.0f, 0.0, 0.0f), FRotator(0.0f, 0.0f, 0.0), ActorSpawnParams);
					statusActor->setValue(rowName_, durationTime, effectAmount);
					combatStatusList.Add(statusActor);
					break;
				}

				case ReduceSpeed:
				{
					UE_LOG(LogTemp, Warning, TEXT("ReduceSpeed Type"));
					ACombatStatusActor* statusActor = GetWorld()->SpawnActor<AReduceSpeedActor>(AReduceSpeedActor::StaticClass(),
						FVector(0.0f, 0.0, 0.0f), FRotator(0.0f, 0.0f, 0.0), ActorSpawnParams);
					statusActor->setValue(rowName_, durationTime, effectAmount);
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

