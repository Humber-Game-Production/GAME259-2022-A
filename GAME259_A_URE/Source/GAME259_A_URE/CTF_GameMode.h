// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Main_PlayerController.h"
#include "GameFramework/GameMode.h"
#include "CTF_GameMode.generated.h"

UCLASS(minimalapi)
class ACTF_GameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ACTF_GameMode();

    virtual void PostLogin(APlayerController* NewPlayer) override;
    //virtual AActor* ChoosePlayerStart_Implementation(AController* player)override;

	float matchTimeLimit;
    float warmupTimeLimit;
	int maxScore;
	int maxRounds;
	int maxPlayers;
	float respawnDelay;

protected:
    virtual void HandleMatchIsWaitingToStart() override;
    virtual void HandleMatchHasStarted() override;

    // Called when the game starts
    virtual void BeginPlay() override;

    TArray<class APlayerSpawnPoint*> SpawnPoints;
    TArray<class APlayerSpawnPoint*> TeamASpawnPoints;
    TArray<class APlayerSpawnPoint*> TeamBSpawnPoints;

    TArray<class AMain_PlayerController*> Players;

    class APlayerSpawnPoint* GetSpawnPoint(TeamSelected owningTeam_);

public:

    void Respawn(AController* Controller);

    UFUNCTION()
        void Spawn(AController* Controller);

protected:

   
};

UENUM(BlueprintType)
enum  class TeamSelected : uint8
{
    NONE          UMETA (DisplayName = "None"),
    TEAM_A        UMETA (DisplayName = "TeamA"),
    TEAM_B        UMETA(DisplayName = "TeamB"),
};