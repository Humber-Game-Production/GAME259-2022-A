// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "CombatStatusComponent.generated.h"

class ACombatStatusActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCombatStatusAdd, FName, statusName);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME259_A_URE_API UCombatStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatStatusComponent();

	UPROPERTY(EditAnywhere, Category = "Data Table")
		UDataTable* CombatStatusTable;

	UPROPERTY(EditAnywhere)
		TArray<ACombatStatusActor*> combatStatusList;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Declare variables
	UPROPERTY(EditAnywhere, Category = "Ball Stat Type")
	bool isFrozen;
	UPROPERTY(EditAnywhere, Category = "Ball Stat Type")
	bool isBurning;

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
		void AddCombatStatus(FName rowName_);

	UFUNCTION(BlueprintCallable)
		void RemoveCombatStatus(ACombatStatusActor* statusActor);

	UFUNCTION(BlueprintCallable)
		void RemoveCombatStatusList();


	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
		FCombatStatusAdd OnCombStatusAdd;

private:

	ACombatStatusActor* existCombatStatus(FName statusName_);

};

//TODO: Enum Class Status Type
UENUM(BlueprintType)
enum EStatusClass{
	Default,
	DamageOverTime,
	ReduceSpeed
};

UENUM(BlueprintType)
enum EStatusType {
	Buff,
	Debuff
};

//DataTable Row
USTRUCT(BlueprintType)
struct FCombatStatus : public FTableRowBase {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float durationTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float effectAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EStatusType> statusType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EStatusClass> statusClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture* icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UParticleSystem* particleEffect;

};
