// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseAbilityComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAbilityUpdate, FName, abilityName, float, cooldown);
UCLASS(Abstract)
class GAME259_A_URE_API UBaseAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBaseAbilityComponent();

	UPROPERTY(VisibleDefaultsOnly, Category = "Timer")
		FTimerHandle TimeHandle;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//Declare variables
	UPROPERTY(EditAnywhere)
		FName abilityName;

	UPROPERTY(EditAnywhere)
		float cooldown;

	UPROPERTY(VisibleDefaultsOnly)
		float cd_countdown;

private:

	virtual bool TriggerAbilityEffect();

	void CooldownCountdown();

public:	

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
		FAbilityUpdate AbilityCooldownUpdate;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		bool ActivateAbility();

	UFUNCTION(BlueprintCallable)
		float getCooldown() { return cooldown; }


};
