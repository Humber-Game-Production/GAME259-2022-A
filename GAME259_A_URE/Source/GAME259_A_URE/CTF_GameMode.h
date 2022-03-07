// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CTF_GameMode.generated.h"

UCLASS(minimalapi)
class ACTF_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACTF_GameMode();
};

    ACTF_GameMode();


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

    class APlayerSpawnPoint* GetSpawnPoint();

public:

    void Respawn(AController* Controller);

    UFUNCTION()
        void Spawn(AController* Controller);

protected:

   
};