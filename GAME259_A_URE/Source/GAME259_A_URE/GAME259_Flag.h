// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"
#include "Components/ActorComponent.h"
#include "GAME259_Flag.generated.h"

/**
 * 
 */
UCLASS()
class GAME259_A_URE_API AGAME259_Flag : public AActor
{
	GENERATED_BODY()
	
public:
	AGAME259_Flag();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(Replicated, EditAnywhere)
	int owningTeam;

};
