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

    UPROPERTY(EditDefaultsOnly)
	float matchTimeLimit;
    UPROPERTY(EditDefaultsOnly)
    float warmupTimeLimit;
    UPROPERTY(EditDefaultsOnly)
	int maxScore;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int maxPlayers;     

    //int maxRounds;    //not used at this point
	//float respawnDelay;   //currently not used, would require coordination with UI respawn widget to have dynamic respawnDelay

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<AActor> flagActor;
    UPROPERTY(BlueprintReadWrite)
    AActor* teamAFlag;
    UPROPERTY(BlueprintReadWrite)
    AActor* teamBFlag;

protected:
    //Called when entering WaitingToStart Match State
    virtual void HandleMatchIsWaitingToStart() override;
    //Used in BP_CTF_GameMode to find each teams flag (flag class is entirely blueprint)
    UFUNCTION(BlueprintImplementableEvent)
    void MatchWaitingToStart();
    //Called after team select in BP_Main_PlayerController to handle when match start process can begin
    UFUNCTION(BLueprintCallable)
    void PlayerJoinedTeam();
    //Called when entering InProgress Match State
    virtual void HandleMatchHasStarted() override;
    //Called when entering WaitingPostMatch Match State
    virtual void HandleMatchHasEnded() override;

    // Called when the game starts
    virtual void BeginPlay() override;

    TArray<class APlayerSpawnPoint*> SpawnPoints;
    TArray<class APlayerSpawnPoint*> TeamASpawnPoints;
    TArray<class APlayerSpawnPoint*> TeamBSpawnPoints;

    TArray<class AMain_PlayerController*> Players;
    TArray<class AMain_PlayerController*> Spectators;

    //Find a spawn point for the player to spawn at
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