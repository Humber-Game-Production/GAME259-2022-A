// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"
#include "Components/ActorComponent.h"
#include "Flag.generated.h"

/**
 * 
 */
UCLASS()
class GAME259_A_URE_API AFlag : public AActor
{
	GENERATED_BODY()
	
public:
	AFlag();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(Replicated, EditAnywhere)
	int owningTeam;

};
