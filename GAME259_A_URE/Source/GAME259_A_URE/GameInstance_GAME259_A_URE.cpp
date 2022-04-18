// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance_GAME259_A_URE.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Engine/World.h"
#include "GameFramework/OnlineSession.h"
#include "Kismet/GameplayStatics.h"
#include "Net/Core/PushModel/PushModel.h"

const FName GlobalOngoingSessionName = FName("GlobalOngoingSessionName");

UGameInstance_GAME259_A_URE::UGameInstance_GAME259_A_URE()
{
	MySessionName = FName("My Session");
}

void UGameInstance_GAME259_A_URE::Init()
{
	if (const IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get()) 
	{
		SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this,&UGameInstance_GAME259_A_URE::OnCreateSessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UGameInstance_GAME259_A_URE::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UGameInstance_GAME259_A_URE::OnJoinSessionComplete);
		}
	}

	if (GEngine)
	{
		GEngine->OnNetworkFailure().AddUObject(this, &UGameInstance_GAME259_A_URE::OnNetworkFailure);
	}
}

void UGameInstance_GAME259_A_URE::OnCreateSessionComplete(FName SessionName, bool Succeeded)
{
	UE_LOG(LogTemp, Warning, TEXT("OnCreateSessionComplete, Succeeded: %d"), Succeeded);
	if (Succeeded)
	{
		GetWorld()->ServerTravel("/Game/Levels/IceMaze?listen");
	}
}

void UGameInstance_GAME259_A_URE::OnFindSessionsComplete(bool Succeeded)
{
	SearchingForServer.Broadcast(false);

	UE_LOG(LogTemp, Warning, TEXT("OnFindSessionComplete, Succeeded: %d"), Succeeded);
	if (Succeeded)
	{
		int32 ArrayIndex = -1;

		for (FOnlineSessionSearchResult Result : SessionSearch->SearchResults)
		{
			/*FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
			{
				UE_LOG(LogTemp, Warning, TEXT("This text will appear in the console 3 seconds after execution"))
			}, 3, false);*/
			++ArrayIndex;
			//if (!Result.IsValid()) // if not valid -> continue
			//{
			//	continue;
			//}
				FServerInfo Info;
				FString ServerName = "Empty Server Name";
				Result.Session.SessionSettings.Get(FName("SERVER_NAME_KEY"), ServerName);
				Info.ServerName = ServerName;
				Info.MaxPlayers = Result.Session.SessionSettings.NumPublicConnections;
				Info.ServerArrayIndex = ArrayIndex;
				ServerListDel.Broadcast(Info);
		}
		UE_LOG(LogTemp, Warning, TEXT("SearchResults, Server Count: %d"), SessionSearch->SearchResults.Num());
	}
}

void UGameInstance_GAME259_A_URE::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (GEngine)
	{
		UE_LOG(LogTemp, Warning, TEXT("OnJoinSessionComplete, SessionName: %s"), *SessionName.ToString());
	}

	// Travel with owning Player Controller
	if (APlayerController* PController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		FString JoinAddress = "";
		SessionInterface->GetResolvedConnectString(SessionName, JoinAddress);
		if (JoinAddress != "")
		{
			PController->ClientTravel(JoinAddress, ETravelType::TRAVEL_Absolute);
		}
	}
}

void UGameInstance_GAME259_A_URE::OnNetworkFailure(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString)
{
	APlayerController* PController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PController->ClientTravel("Game/UI/Maps/L_MainMenu", ETravelType::TRAVEL_Absolute); // May Change this line of code 
}

void UGameInstance_GAME259_A_URE::CreateServer(FServerMatchSettingsInfo ServerMatchSettingsInfo_)
{
	FOnlineSessionSettings SessionSettings;
	SessionSettings.bAllowJoinInProgress = true;
	SessionSettings.bIsDedicated = false;
	
	// Easy Testing between OnlineSubsystemNULL & OnlineSubsystemSteam | Change system in "defaultEngine.ini"
	if (IOnlineSubsystem::Get()->GetSubsystemName() != "NULL")
	{
		SessionSettings.bIsLANMatch = false;
	}
	else
	{
		SessionSettings.bIsLANMatch = true; 
	}
	SessionSettings.bShouldAdvertise = true;
	SessionSettings.bUsesPresence = true;
	SessionSettings.NumPublicConnections = ServerMatchSettingsInfo_.MaxPlayers + 1; // + 1 Spectator Count
	SessionSettings.bUseLobbiesIfAvailable = true;

	// Set Server Names
	SessionSettings.Set(FName("SERVER_NAME_KEY"), ServerMatchSettingsInfo_.ServerName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);
	
	// Creates Session/Server
	SessionInterface->CreateSession(0, GlobalOngoingSessionName, SessionSettings);
}

void UGameInstance_GAME259_A_URE::DestroySession(FName SessionName, bool Succeeded)
{
	SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UGameInstance_GAME259_A_URE::OnDestroySessionComplete);
	SessionInterface->EndSession(GlobalOngoingSessionName);
	SessionInterface->DestroySession(GlobalOngoingSessionName);
}

void UGameInstance_GAME259_A_URE::OnDestroySessionComplete(FName SessionName, bool Succeeded)
{
	SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UGameInstance_GAME259_A_URE::OnDestroySessionComplete);
	SessionInterface->ClearOnDestroySessionCompleteDelegates(this);
}

void UGameInstance_GAME259_A_URE::FindServers()
{
	SearchingForServer.Broadcast(true);

	if (GEngine)
	{
		UE_LOG(LogTemp, Warning, TEXT("Find Servers Called"));
	}

	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	
	// Easy Testing between OnlineSubsystemNULL & OnlineSubsystemSteam | Change system in "defaultEngine.ini"
	if (IOnlineSubsystem::Get()->GetSubsystemName() != "NULL")
	{
		SessionSearch->bIsLanQuery = false;
	}
	else
	{
		SessionSearch->bIsLanQuery = true; 
	}

	// High number because of Steam App ID is similar to other developers
	SessionSearch->MaxSearchResults = 10000; 
	
	SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);
	SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
	
}

void UGameInstance_GAME259_A_URE::JoinServer(int32 ArrayIndex)
{
	const FOnlineSessionSearchResult Result = SessionSearch->SearchResults[ArrayIndex];
	if (Result.IsValid())
	{
		if(GEngine)
		{
			UE_LOG(LogTemp, Warning, TEXT("JOINING SERVER at index: %d"), ArrayIndex);
			SessionInterface->JoinSession(0, MySessionName, Result);
		}
	}
	else
	{
		if (GEngine)
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to JOIN SERVER at index: %d"), ArrayIndex);
		}
	}
}


