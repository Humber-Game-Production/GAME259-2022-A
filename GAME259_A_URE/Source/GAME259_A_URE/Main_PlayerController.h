// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Main_PlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterDeathEventDispatcher);

/**
 * 
 */
UCLASS()
class GAME259_A_URE_API AMain_PlayerController : public APlayerController
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
public:

	// Event that will be triggered in the blueprint when player respawns
	UFUNCTION(BlueprintImplementableEvent)
	void RespawnEvent();

	// Event that will be triggered in the blueprint when player dies
	UFUNCTION(BlueprintImplementableEvent)
	void DeathEvent();

	//UFUNCTION(BlueprintImplementableEvent)
	//void HealthUpdateEvent();

	//UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
	//FCharacterDeathEventDispatcher DeathEventDispatcher;
};
