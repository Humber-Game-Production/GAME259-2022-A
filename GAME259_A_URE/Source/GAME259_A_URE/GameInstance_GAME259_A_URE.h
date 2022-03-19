// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Engine/GameInstance.h"
#include "GameInstance_GAME259_A_URE.generated.h"

// Allows for visible servers on scroll box of Lobby UI
USTRUCT(BlueprintType)
struct FServerInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FString ServerName;
	UPROPERTY(BlueprintReadOnly)
	int32 CurrentPlayers;
	UPROPERTY(BlueprintReadOnly)
	int32 MaxPlayers;
	UPROPERTY(BlueprintReadOnly)
	int32 ServerArrayIndex;
};

// Delegate for ServerList Loading
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FServerDel, FServerInfo, ServerListDel);

// Checks if "Refresh Server" is active
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FServerSearchingDel, bool, SearchingForServer);


UCLASS()
class GAME259_A_URE_API UGameInstance_GAME259_A_URE : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UGameInstance_GAME259_A_URE();

protected:
	FName MySessionName;

	// Handles matchmaking of players | Sessions
	IOnlineSessionPtr SessionInterface;

	// Searching/storing sessions
	TSharedPtr<FOnlineSessionSearch> SessionSearch;

	UPROPERTY(BlueprintAssignable)
	FServerDel ServerListDel;

	UPROPERTY(BlueprintAssignable)
	FServerSearchingDel SearchingForServer;;

	// Gets OnlineSubsystemNULL and/or OnlineSubsystemSteam
	virtual void Init() override;
	
	// Delegates called on Init(), if session is valid
	virtual void OnCreateSessionComplete(FName SessionName, bool Succeeded);
	virtual void OnFindSessionsComplete(bool Succeeded);
	virtual void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	
	UFUNCTION(BlueprintCallable)
	void CreateServer(FString ServerName);

	UFUNCTION(BlueprintCallable)
	void FindServers();

	UFUNCTION(BlueprintCallable)
	void JoinServer(int32 ArrayIndex);
};
