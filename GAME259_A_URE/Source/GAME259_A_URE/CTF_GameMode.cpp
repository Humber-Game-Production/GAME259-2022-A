// Copyright Epic Games, Inc. All Rights Reserved.

#include "CTF_GameMode.h"
#include "Main_Character.h"
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
	PlayerControllerClass = APlayerController::StaticClass();

	timeLimit = 300.0f;
	maxScore = 3;
	maxRounds = 3;
	maxPlayers = 8;
	respawnDelay = 5.0f;

	team1 = true;
	team2 = false;
}

void ACTF_GameMode::BeginPlay()
{
	Super::BeginPlay();

	UClass* SpawnPointClass = APlayerSpawnPoint::StaticClass();

	//Add refference to team1 SpawnPoints
	for (TActorIterator<AActor> Actor(GetWorld(), SpawnPointClass); Actor; ++Actor)
	{
		SpawnPoints.Add(Cast<APlayerSpawnPoint>(*Actor));

	}
}

void ACTF_GameMode::Respawn(AController* Controller)
{
	if (Controller)
	{
		if (HasAuthority())
		{
			FTimerDelegate RespawnDele;
			FTimerHandle RespawnHandle;
			RespawnDele.BindUFunction(this, FName("Spawn"), Controller);
			GetWorld()->GetTimerManager().SetTimer(RespawnHandle, RespawnDele, 3.0f, false);
		}
	}
}

APlayerSpawnPoint* ACTF_GameMode::GetSpawnPoint()
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

void ACTF_GameMode::Spawn(AController* Controller)
{
	//Team 1 spawning system
	if (team1 == true)
	{
		if (APlayerSpawnPoint* SpawnPoint = GetSpawnPoint())
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