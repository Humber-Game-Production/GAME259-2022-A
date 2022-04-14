// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Net/UnrealNetwork.h"
#include "CTF_GameMode.h"
#include "Main_Character.h"
#include "CTF_GameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMatchTimeRemaining, int, timeRemaining_);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMatchHasEnded, TeamSelected, winningTeam_);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerKilledDelegate, AMain_Character*, playerKilled);

UCLASS()
class GAME259_A_URE_API ACTF_GameState : public AGameState
{
	GENERATED_BODY()

public:
	ACTF_GameState();

	void MatchStartCountdownTick();
	void MatchTick();

	void PlayerDied(AMain_Character* deadPlayer_);

	float warmupStartTime;
	float matchStartTime;

	UPROPERTY(BlueprintReadOnly, Replicated)
	int timeRemaining;

	UPROPERTY(BlueprintReadWrite)
	int numTeamAPlayers;
	UPROPERTY(BlueprintReadWrite)
	int numTeamBPlayers;

	UPROPERTY(BlueprintReadWrite)
	int teamAScore;
	UPROPERTY(BlueprintReadWrite)
	int teamBScore;

	//Not currently implemented
	/*UPROPERTY(BlueprintReadOnly)
	int teamARoundsWon;
	UPROPERTY(BlueprintReadOnly)
	int teamBRoundsWon;*/

	UPROPERTY(BlueprintReadWrite)
	FlagState teamAFlagState;
	UPROPERTY(BlueprintReadWrite)
	FlagState teamBFlagState;

	//Not currently implemeted
	/*UPROPERTY(BlueprintReadOnly)
	bool isOvertime;*/
	
	FTimerHandle MatchStartCountdown;
	FTimerHandle MatchTimer;
	FTimerHandle EndOfMatchTimer;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
	FMatchTimeRemaining MatchTimeRemainingUpdate;
	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
	FMatchHasEnded MatchHasEndedUpdate;
	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
	FPlayerKilledDelegate PlayerKilled;;
};
