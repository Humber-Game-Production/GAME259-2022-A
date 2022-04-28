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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UBallRepulsorComponent();

	UPROPERTY(VisibleDefaultsOnly)
		class ABallRepulsorActor* collisionActor;

	UPROPERTY(VisibleDefaultsOnly, Category = "Timer")
		FTimerHandle CollisionTimeHandle;

	UPROPERTY(VisibleDefaultsOnly, Category = "Timer")
		FTimerHandle AbilityTimeHandle;

	UPROPERTY(EditDefaultsOnly, Category = "Timer")
		float durationTime;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ABallRepulsorActor> BallRepulsorClass;



	UFUNCTION(BlueprintCallable)
		bool TriggerAbilityEffect() override;

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
		void AddCollisionComp_Multicast();

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void AddCollisionComp_Server();

	UFUNCTION(BlueprintCallable)
		void EndAbility();

	UFUNCTION(BlueprintCallable)
		void OnDestroy();


};
