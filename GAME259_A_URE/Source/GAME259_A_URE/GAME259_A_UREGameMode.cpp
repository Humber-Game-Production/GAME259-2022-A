// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAME259_A_UREGameMode.h"
#include "GAME259_A_URECharacter.h"
#include "GAME259_GameState.h"
#include "GAME259_PlayerController.h"
#include "GAME259_PLayerSpawnPoint.h"
#include "EngineUtils.h"
#include "Math/UnrealMathUtility.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"

AGAME259_A_UREGameMode::AGAME259_A_UREGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_GAME259_A_URECharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	GameStateClass = AGAME259_GameState::StaticClass();
	PlayerControllerClass = AGAME259_PlayerController::StaticClass();

	timeLimit = 300.0f;
	maxScore = 3;
	maxRounds = 3;
	maxPlayers = 8;
	respawnDelay = 5.0f;

	team1 = true;
	team2 = false;
}

void AGAME259_A_UREGameMode::BeginPlay()
{
	Super::BeginPlay();

	UClass* SpawnPointClass = AGAME259_PlayerSpawnPoint::StaticClass();

	//Add refference to team1 SpawnPoints
	for (TActorIterator<AActor> Actor(GetWorld(), SpawnPointClass); Actor; ++Actor)
	{
		SpawnPoints.Add(Cast<AGAME259_PlayerSpawnPoint>(*Actor));

	}
}

void AGAME259_A_UREGameMode::Respawn(AController* Controller)
{
	if (Controller)
	{
		if (HasAuthority())
		{
			FTimerDelegate RespawnDele;
			RespawnDele.BindUFunction(this, FName("Spawn"), Controller);
			GetWorld()->GetTimerManager().SetTimer(RespawnHandle, RespawnDele, 3.0f, false);
		}
	}
}

AGAME259_PlayerSpawnPoint* AGAME259_A_UREGameMode::GetSpawnPoint()
{
	//Gets the total team1 spawn points
	for (int32 i = 0 < SpawnPoints.Num(); ++i;)
	{
		int32 Slot = FMath::RandRange(0, SpawnPoints.Num() - 1);
		if (SpawnPoints[Slot])
		{
			return SpawnPoints[Slot];
		}

	}

	return nullptr;
}

void AGAME259_A_UREGameMode::Spawn(AController* Controller)
{
	//Team 1 spawning system
	if (team1 == true)
	{
		if (AGAME259_PlayerSpawnPoint* SpawnPoint = GetSpawnPoint())
		{
			FVector LocationOffset = FVector(0.0f, 0.0f, 0.0f);
			FVector Location = SpawnPoint->GetActorLocation() + LocationOffset;
			FRotator Rotation = SpawnPoint->GetActorRotation();
			if (APawn* Pawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, Location, FRotator::ZeroRotator))
			{
				Controller->Possess(Pawn);
			}
		}

	}
	/*Team 2 spawning system
	if (team2 == true)
	{
		if (ASpawnPointT2* SpawnPointT2 = GetSpawnPointT2())
		{
			FVector Location = SpawnPointT2->GetActorLocation();
			FRotator Rotation = SpawnPointT2->GetActorRotation();
			if (APawn* Pawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, Location, FRotator::ZeroRotator))
			{
				Controller->Possess(Pawn);
			}
		}
	}*/
}