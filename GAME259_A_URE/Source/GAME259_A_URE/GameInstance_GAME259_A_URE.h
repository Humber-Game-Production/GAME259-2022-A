// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "CTF_GameMode.h"
#include "Engine/GameInstance.h"
#include "GameInstance_GAME259_A_URE.generated.h"

// Editable Match Settings before creating Listen Server
USTRUCT(BlueprintType)
struct FServerMatchSettingsInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	FString ServerName;
	
	UPROPERTY(BlueprintReadWrite)
	int32 MaxPlayers;

	UPROPERTY(BlueprintReadWrite)
	int32 MatchTimer;

	UPROPERTY(BlueprintReadWrite)
	int32 MaxScore;
};

// Allows for visible servers on scroll box of Lobby UI
USTRUCT(BlueprintType)
struct FServerInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FString ServerName;
	
	UPROPERTY(BlueprintReadOnly)
	int32 MaxPlayers;
	
	UPROPERTY(BlueprintReadOnly)
	int32 MatchTimer;

	UPROPERTY(BlueprintReadOnly)
	int32 MaxScore;
	
	UPROPERTY(BlueprintReadOnly)
	int32 ServerArrayIndex;
};

// Delegate for ServerList Loading
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FServerDel, FServerInfo, ServerListDel);

// Checks if "Refresh Server" is active
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FServerSearchingDel, bool, SearchingForServer);

// Map Selection
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMapSelectionDel, FString, MapNameDel);


UCLASS()
class GAME259_A_URE_API UGameInstance_GAME259_A_URE : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UGameInstance_GAME259_A_URE();

	UPROPERTY(BlueprintReadWrite)
	int32 GameInstanceMaxPlayers;

	UPROPERTY(BlueprintReadWrite)
	int32 GameInstanceMatchTimer;

	UPROPERTY(BlueprintReadWrite)
	int32 GameInstanceMaxScore;

protected:
	FName MySessionName;

	// Handles matchmaking of players | Sessions
	IOnlineSessionPtr SessionInterface;

	// Searching/storing sessions
	TSharedPtr<FOnlineSessionSearch> SessionSearch;

	// Delegates
	UPROPERTY(BlueprintAssignable)
	FServerDel ServerListDel;

	UPROPERTY(BlueprintAssignable)
	FServerSearchingDel SearchingForServer;
	
	// Gets OnlineSubsystemNULL and/or OnlineSubsystemSteam
	virtual void Init() override;
	
	// Delegates called on Init(), if session is valid
	virtual void OnCreateSessionComplete(FName SessionName, bool Succeeded);
	virtual void OnFindSessionsComplete(bool Succeeded);
	virtual void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	
	// Returns players to main menu if Network Failure Occurs
	void OnNetworkFailure(UWorld* GetGameWorld, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString);
	
	UFUNCTION(BlueprintCallable)
	void CreateServer(FServerMatchSettingsInfo ServerMatchSettingsInfo_);

	UFUNCTION(BlueprintCallable)
	void FindServers();

	UFUNCTION(BlueprintCallable)
	void JoinServer(int32 ArrayIndex);
	
	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
	void DestroySession_Multicast(FName SessionName, bool Succeeded);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void DestroySession_Server(FName SessionName, bool Succeeded);
	
	void OnDestroySessionComplete(FName SessionName, bool Succeeded);

private:


};
