// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatStatusActor.h"
#include "ReduceSpeedActor.generated.h"

/**
 * 
 */
UCLASS()
class GAME259_A_URE_API AReduceSpeedActor : public ACombatStatusActor
{
	GENERATED_BODY()

public:
	AReduceSpeedActor();
	
protected:
	void ApplyEffect() override;

};
