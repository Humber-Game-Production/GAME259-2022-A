// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatStatusActor.h"
#include "DamageOverTimeActor.generated.h"

/**
 * 
 */
UCLASS()
class GAME259_A_URE_API ADamageOverTimeActor : public ACombatStatusActor
{
	GENERATED_BODY()

public:
	ADamageOverTimeActor();

protected:
	void ApplyEffect() override;

};
