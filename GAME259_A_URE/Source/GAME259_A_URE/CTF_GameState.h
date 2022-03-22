// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "CTF_GameState.generated.h"

/**
 * 
 */
UCLASS()
class GAME259_A_URE_API ACTF_GameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ACTF_GameState();

	float timeElapsed;
	int team1Score;
	int team2Score;
	int team1RoundsWon;
	int team2RoundsWon;
	bool isOvertime;
	
};
