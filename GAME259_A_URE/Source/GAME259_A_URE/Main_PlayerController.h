// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Main_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAME259_A_URE_API AMain_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	FTimerHandle RespawnHandle;
};
