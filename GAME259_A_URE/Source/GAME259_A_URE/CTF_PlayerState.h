// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CTF_GameMode.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/PlayerState.h"
#include "CTF_PlayerState.generated.h"



/**
 * 
 */
UCLASS()
class GAME259_A_URE_API ACTF_PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ACTF_PlayerState();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const override;

	UPROPERTY(BlueprintReadWrite, Replicated)
	TeamSelected team;
	UPROPERTY(BlueprintReadWrite, Replicated)
	bool isCarryingFlag;
	UPROPERTY(BlueprintReadOnly, Replicated)
	bool isSpectator_CTF;
};
