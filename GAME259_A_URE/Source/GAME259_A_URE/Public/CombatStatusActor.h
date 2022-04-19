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

protected:

	UPROPERTY(VisibleDefaultsOnly)
	FName statusName;

	UPROPERTY(VisibleDefaultsOnly)
	float durationTime;

	UPROPERTY(VisibleDefaultsOnly)
	float remainTime;

	UPROPERTY(VisibleDefaultsOnly)
	float effectAmount;

	UPROPERTY(VisibleDefaultsOnly)
	FString description;

	UPROPERTY(VisibleDefaultsOnly)
	UTexture2D* icon;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void ApplyEffect();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
	FCombatStatusDestroy OnCombStatusRemove;

	UFUNCTION(BlueprintCallable)
	void setValue(FName statusName_, float durationTime_, float effectAmount_, 
	UParticleSystem* particleEffect_, FString description_, UTexture2D* icon_);

	UFUNCTION(BlueprintCallable)
	FName getName() { return statusName; }

	UFUNCTION(BlueprintCallable)
	FString getDescription() { return description; }

	UFUNCTION(BlueprintCallable)
	UTexture* getIcon() { return icon; }

	UFUNCTION(BlueprintCallable)
	float getEffectAmount() { return effectAmount; }

	UFUNCTION(BlueprintCallable)
	float getRemainTime() { return remainTime; }

	UFUNCTION(BlueprintCallable)
	void refreshTime() { remainTime = durationTime; }

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
		void OnDestroy_Multicast();

	
	UFUNCTION(BlueprintCallable, Server, Reliable)
		void OnDestroy_Server();
};

