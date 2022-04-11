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

	float matchTimeLimit;
    float warmupTimeLimit;
	int maxScore;
	int maxRounds;
    UPROPERTY(BlueprintReadOnly)
	int maxPlayers;
	float respawnDelay;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<AActor> flagActor;
    UPROPERTY(BlueprintReadWrite)
    AActor* teamAFlag;
    UPROPERTY(BlueprintReadWrite)
    AActor* teamBFlag;

protected:
    virtual void HandleMatchIsWaitingToStart() override;
    UFUNCTION(BlueprintImplementableEvent)
    void MatchWaitingToStart();
    UFUNCTION(BLueprintCallable)
    void PlayerJoinedTeam();
    virtual void HandleMatchHasStarted() override;
    virtual void HandleMatchHasEnded() override;

    // Called when the game starts
    virtual void BeginPlay() override;

    TArray<class APlayerSpawnPoint*> SpawnPoints;
    TArray<class APlayerSpawnPoint*> TeamASpawnPoints;
    TArray<class APlayerSpawnPoint*> TeamBSpawnPoints;

    TArray<class AMain_PlayerController*> Players;

    class APlayerSpawnPoint* GetSpawnPoint(TeamSelected owningTeam_);


public:
    UFUNCTION()
    void Respawn(AController* Controller);

    UFUNCTION(BlueprintCallable)
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

UENUM(BlueprintType)
enum  class FlagState : uint8
{
    SAFE          UMETA(DisplayName = "Safe"),
    STOLEN        UMETA(DisplayName = "Stolen"),
    DROPPED       UMETA(DisplayName = "Dropped"),
};