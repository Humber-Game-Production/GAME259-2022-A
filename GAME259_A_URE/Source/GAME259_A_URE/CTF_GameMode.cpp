// Copyright Epic Games, Inc. All Rights Reserved.

#include "CTF_GameMode.h"
#include "Main_Character.h"
#include "Main_PlayerController.h"
#include "CTF_PlayerState.h"
#include "CTF_GameState.h"
#include "PLayerSpawnPoint.h"
#include "EngineUtils.h"
#include "Math/UnrealMathUtility.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"

ACTF_GameMode::ACTF_GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_Main_Character"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	GameStateClass = ACTF_GameState::StaticClass();
	PlayerControllerClass = AMain_PlayerController::StaticClass();
	PlayerStateClass = ACTF_PlayerState::StaticClass();

	timeLimit = 300.0f;
	maxScore = 3;
	maxRounds = 3;
	maxPlayers = 8;
	respawnDelay = 5.0f;
}

void ACTF_GameMode::PostLogin(APlayerController* NewPlayer)
{
	ACTF_GameMode::Super::PostLogin(NewPlayer);
	if (AMain_PlayerController* PlayerController = Cast<AMain_PlayerController>(NewPlayer))
	{
		if (GameState->PlayerArray.Num() % 2 != 0)
		{
			PlayerController->GetPlayerState<ACTF_PlayerState>()->bIsTeamA = false;
			PlayerController->GetPlayerState<ACTF_PlayerState>()->SetPlayerName("TeamA");
		}
		else
		{
			PlayerController->GetPlayerState<ACTF_PlayerState>()->SetPlayerName("TeamB");
		}
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, PlayerController->GetPlayerState<ACTF_PlayerState>()->GetPlayerName());
	}
}

void ACTF_GameMode::BeginPlay()
{
	Super::BeginPlay();

	UClass* SpawnPointClass = APlayerSpawnPoint::StaticClass();

	//Add refference to team1 SpawnPoints
	for (TActorIterator<AActor> Actor(GetWorld(), SpawnPointClass); Actor; ++Actor)
	{
		if (APlayerSpawnPoint* PlayerSpawnPoint = Cast<APlayerSpawnPoint>(*Actor)) {
			if (PlayerSpawnPoint->bIsTeamASpawn == true) {
				TeamASpawnPoints.Add(Cast<APlayerSpawnPoint>(*Actor));
			}
			else if (PlayerSpawnPoint->bIsTeamASpawn == false) {
				TeamBSpawnPoints.Add(Cast<APlayerSpawnPoint>(*Actor));
			}
			else {
				SpawnPoints.Add(Cast<APlayerSpawnPoint>(*Actor));
			}
		}
	}
}

void ACTF_GameMode::Respawn(AController* Controller)
{
	if (AMain_PlayerController* PlayerController = Cast<AMain_PlayerController>(Controller))
	{
		if (HasAuthority())
		{
			FTimerDelegate RespawnDele;
			FTimerHandle RespawnHandle;
			RespawnDele.BindUFunction(this, FName("Spawn"), PlayerController);
			GetWorld()->GetTimerManager().SetTimer(RespawnHandle, RespawnDele, 3.0f, false);
		}
	}
}

APlayerSpawnPoint* ACTF_GameMode::GetSpawnPoint(bool bIsTeamA_)
{
	//Gets the total teamA spawn points
	if (bIsTeamA_ == true) {
		for (int32 i = 0 < TeamASpawnPoints.Num(); ++i;)
		{
			int32 Slot = FMath::RandRange(0, TeamASpawnPoints.Num() - 1);
			if (TeamASpawnPoints[Slot])
			{
				return TeamASpawnPoints[Slot];
			}
		}
	}
	//Gets the total teamB spawn points
	if (bIsTeamA_ == false) {
		for (int32 i = 0 < TeamBSpawnPoints.Num(); ++i;)
		{
			int32 Slot = FMath::RandRange(0, TeamBSpawnPoints.Num() - 1);
			if (TeamBSpawnPoints[Slot])
			{
				return TeamBSpawnPoints[Slot];
			}
		}
	}
	

	return nullptr;
}

void ACTF_GameMode::Spawn(AController* Controller)
{
	if (AMain_PlayerController* PlayerController = Cast<AMain_PlayerController>(Controller))
	{
		//Team A Spawn
		if (PlayerController->GetPlayerState<ACTF_PlayerState>()->bIsTeamA == true)
		{
			if (APlayerSpawnPoint* SpawnPoint = GetSpawnPoint(true))
			{
				FVector LocationOffset = FVector(0.0f, 0.0f, 0.0f);
				FVector Location = SpawnPoint->GetActorLocation() + LocationOffset;
				FRotator Rotation = SpawnPoint->GetActorRotation();
				if (APawn* Pawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, Location, FRotator::ZeroRotator))
				{
					PlayerController->Possess(Pawn);
				}
			}
		}
		//Team B Spawn
		if (PlayerController->GetPlayerState<ACTF_PlayerState>()->bIsTeamA == false)
		{
			if (APlayerSpawnPoint* SpawnPoint = GetSpawnPoint(false))
			{
				FVector LocationOffset = FVector(0.0f, 0.0f, 0.0f);
				FVector Location = SpawnPoint->GetActorLocation() + LocationOffset;
				FRotator Rotation = SpawnPoint->GetActorRotation();
				if (APawn* Pawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, Location, FRotator::ZeroRotator))
				{
					PlayerController->Possess(Pawn);
				}
			}
		}
	}
}