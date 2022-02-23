// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GAME259_A_UREGameMode.generated.h"

UCLASS(minimalapi)
class AGAME259_A_UREGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGAME259_A_UREGameMode();


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

	FTimerHandle RespawnHandle;

    TArray<class AGAME259_PlayerSpawnPoint*> SpawnPoints;

    class AGAME259_PlayerSpawnPoint* GetSpawnPoint();

public:

    void Respawn(AController* Controller);

    UFUNCTION()
        void Spawn(AController* Controller);

protected:

   
};
