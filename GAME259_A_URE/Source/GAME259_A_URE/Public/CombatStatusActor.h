// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CombatStatusActor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCombatStatusDestroy, ACombatStatusActor*, statusActor);
UCLASS(ABSTRACT)
class GAME259_A_URE_API ACombatStatusActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACombatStatusActor();
	ACombatStatusActor(float durationTime_, float effectAmount_);

	UPROPERTY(VisibleDefaultsOnly, Category = "Timer")
		FTimerHandle TimeHandle;

	UPROPERTY(VisibleAnywhere, Category = "Particle Effect")
		class UParticleSystemComponent* ParticleComponent;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
		FCombatStatusDestroy OnCombStatusRemove;

	UFUNCTION()
		void setValue(FName statusName_, float durationTime_, float effectAmount_, UParticleSystem* particleEffect_);



protected:

	FName statusName;

	float durationTime;

	float remainTime;

	float effectAmount;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		virtual void ApplyEffect();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
