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
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class ABallRepulsorActor* collisionActor;

	UPROPERTY(VisibleDefaultsOnly, Category = "Timer")
		FTimerHandle AbilityTimeHandle;

	UFUNCTION(BlueprintCallable)
		bool TriggerAbilityEffect() override;

	UFUNCTION(BlueprintCallable)
		void AddCollisionComp();

	UFUNCTION(BlueprintCallable)
		void EndAbility();

	UFUNCTION(BlueprintCallable)
		void OnDestroy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
