// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAbilityComponent.h"
#include "BallRepulsorComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAME259_A_URE_API UBallRepulsorComponent : public UBaseAbilityComponent
{
	GENERATED_BODY()

public:

	UBallRepulsorComponent();
	
	UFUNCTION(BlueprintCallable)
		void TriggerAbilityEffect() override;


};
