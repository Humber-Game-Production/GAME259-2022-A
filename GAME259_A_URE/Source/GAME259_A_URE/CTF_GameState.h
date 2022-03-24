// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "CTF_GameMode.h"
#include "CTF_GameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMatchTimeRemaining, int, timeRemaining_);

UCLASS()
class GAME259_A_URE_API ACTF_GameState : public AGameState
{
	GENERATED_BODY()

public:
	ACTF_GameState();

	void MatchStartCountdownTick();
	void MatchTick();

	float warmupStartTime;
	float matchStartTime;
	int team1Score;
	int team2Score;
	int team1RoundsWon;
	int team2RoundsWon;
	bool isOvertime;
	
	FTimerHandle MatchStartCountdown;
	FTimerHandle MatchTimer;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
	FMatchTimeRemaining MatchTimeRemainingUpdate;
};
