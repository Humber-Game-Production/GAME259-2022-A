// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "CombatStatusComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME259_A_URE_API UCombatStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatStatusComponent();

	UPROPERTY(EditAnywhere, Category = "Timer")
		FTimerHandle TimeHandle;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Declare variables
	// TODO: Add following variables
	// Duration Time (how long will the status be on the player)
	// Name of the status
	// Type of the status: Enum

	
	//Declare functions
	//ApplyEffect

};

//TODO: Enum Class Status Type


//DataTable Row
USTRUCT(BlueprintType)
struct FCombatStatus : public FTableRowBase {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float durationTime;


};
