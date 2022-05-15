// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Main_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAME259_A_URE_API AMain_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AMain_PlayerController();
	virtual void BeginPlay() override;

	FTimerHandle RespawnHandle;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	class USoundBase* StartSound;

	UFUNCTION(BlueprintCallable, Client, Reliable)
	void PlaySound_Client();

	void PlaySound_Client_Implementation();


};
