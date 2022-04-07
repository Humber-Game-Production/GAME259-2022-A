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

	UPROPERTY(EditAnywhere)
		class ABallRepulsorActor *collisionActor;

	UFUNCTION(BlueprintCallable)
		bool TriggerAbilityEffect() override;

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
		void AddCollisionComp();

	UFUNCTION(BlueprintCallable)
		void OnDestroy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
