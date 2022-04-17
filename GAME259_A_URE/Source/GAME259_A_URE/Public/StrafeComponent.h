// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAbilityComponent.h"
#include "StrafeComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAME259_A_URE_API UStrafeComponent : public UBaseAbilityComponent
{
	GENERATED_BODY()

public:
	UStrafeComponent();

	UPROPERTY(EditAnywhere, Category = "Direction")
		bool forwardVector;

	UFUNCTION(BlueprintCallable)
		bool TriggerAbilityEffect() override;

	UFUNCTION(Server, Reliable, WithValidation)
		void Strafe_Server();

	UFUNCTION(NetMulticast, Reliable)
		void Strafe_Multicast();
};
