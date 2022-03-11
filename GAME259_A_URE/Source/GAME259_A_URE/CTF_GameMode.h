// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Main_PlayerController.h"
#include "GameFramework/GameModeBase.h"
#include "CTF_GameMode.generated.h"

UCLASS(minimalapi)
class ACTF_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACTF_GameMode();

    virtual void PostLogin(APlayerController* NewPlayer) override;


	float timeLimit;
	int maxScore;
	int maxRounds;
	int maxPlayers;
	float respawnDelay;

public:
    bool team1;
    bool team2;

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

    TArray<class APlayerSpawnPoint*> SpawnPoints;
    TArray<class APlayerSpawnPoint*> TeamASpawnPoints;
    TArray<class APlayerSpawnPoint*> TeamBSpawnPoints;

    class APlayerSpawnPoint* GetSpawnPoint(bool bIsTeamA_);

public:

    void Respawn(AController* Controller);

    UFUNCTION()
        void Spawn(AController* Controller);

protected:

   
};