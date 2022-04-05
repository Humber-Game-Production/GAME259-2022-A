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
	//Default Classes, changed to BP versions in BP_CTF_GameMode
	GameStateClass = ACTF_GameState::StaticClass();
	PlayerControllerClass = AMain_PlayerController::StaticClass();
	PlayerStateClass = ACTF_PlayerState::StaticClass();
	DefaultPawnClass = AMain_Character::StaticClass();

	matchTimeLimit = 20.0f;
	warmupTimeLimit = 10.0f;
	maxScore = 3;
	maxRounds = 3;
	maxPlayers = 2;
	respawnDelay = 5.0f;

	bDelayedStart = true;
	bUseSeamlessTravel = true;

}

void ACTF_GameMode::HandleMatchIsWaitingToStart() {

	Super::HandleMatchIsWaitingToStart();

	//TODO: check if this is a restarted game somehow, setup warmup timer outside post login

	UClass* SpawnPointClass = APlayerSpawnPoint::StaticClass();

	for (TActorIterator<AActor> Actor(GetWorld(), SpawnPointClass); Actor; ++Actor)
	{
		if (APlayerSpawnPoint* PlayerSpawnPoint = Cast<APlayerSpawnPoint>(*Actor)) {
			if (PlayerSpawnPoint->owningTeam == TeamSelected::TEAM_A) {
				TeamASpawnPoints.Add(Cast<APlayerSpawnPoint>(*Actor));
			}
			else if (PlayerSpawnPoint->owningTeam == TeamSelected::TEAM_B) {
				TeamBSpawnPoints.Add(Cast<APlayerSpawnPoint>(*Actor));
			}

			else if (PlayerSpawnPoint->owningTeam == TeamSelected::NONE) {
				SpawnPoints.Add(Cast<APlayerSpawnPoint>(*Actor));
			}
		}
	}

	for (AMain_PlayerController* PC : Players) {
		Spawn(PC);
	}
	MatchWaitingToStart();
}
 
void ACTF_GameMode::PostLogin(APlayerController* NewPlayer)
{
	//if players.Num >= max players max NewPlayer forced spectator potentially

	Super::PostLogin(NewPlayer);

	if (AMain_PlayerController* PlayerController = Cast<AMain_PlayerController>(NewPlayer))
	{
		Players.Add(PlayerController);
		if (Players.Num() % 2 == 0) {
			PlayerController->GetPlayerState<ACTF_PlayerState>()->team = TeamSelected::TEAM_A;
		}
		else {
			PlayerController->GetPlayerState<ACTF_PlayerState>()->team = TeamSelected::TEAM_B;
		}
		if (GetMatchState() != MatchState::EnteringMap) {
			Spawn(PlayerController);
		}
	}
	if (Players.Num() < maxPlayers) {
		return;
	}
	if (ACTF_GameState* GS = Cast<ACTF_GameState>(GetWorld()->GetGameState())) {
		if (GS->MatchStartCountdown.IsValid()) {
			return;
		}
		GS->warmupStartTime = GS->GetServerWorldTimeSeconds();
		GetWorldTimerManager().SetTimer(GS->MatchStartCountdown, GS, &ACTF_GameState::MatchStartCountdownTick, 1.0f, true, 0.0f);
	}
}

void ACTF_GameMode::HandleMatchHasStarted() {

	ACTF_GameMode::Super::HandleMatchHasStarted();

	if (ACTF_GameState* GS = Cast<ACTF_GameState>(GetWorld()->GetGameState())) {
		GetWorldTimerManager().SetTimer(GS->MatchTimer, GS, &ACTF_GameState::MatchTick, 1.0f, true, 0.0f);
		GS->matchStartTime = GS->GetServerWorldTimeSeconds();
		GS->timeRemaining = matchTimeLimit;
		for (AMain_PlayerController* PC : Players) {
			if (AMain_Character* Character = Cast<AMain_Character>(PC->GetPawn())) {
				Character->TakeDamage(100.0f, FDamageEvent(), PC, this);
			}
		}
	}
}

void ACTF_GameMode::BeginPlay()
{
	Super::BeginPlay();

	
}

void ACTF_GameMode::HandleMatchHasEnded() 
{
	Super::HandleMatchHasEnded();

	if (ACTF_GameState* GS = Cast<ACTF_GameState>(GetWorld()->GetGameState())) {
		GetWorld()->GetTimerManager().ClearTimer(GS->MatchTimer);
		GS->MatchTimer.Invalidate();
		FTimerDelegate RespawnDele;
		RespawnDele.BindUFunction(this, FName("RestartGame"));
		GetWorldTimerManager().SetTimer(GS->EndOfMatchTimer, RespawnDele, 0.1f, false);
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

APlayerSpawnPoint* ACTF_GameMode::GetSpawnPoint(TeamSelected owningTeam_)
{
	//Gets the total teamA spawn points
	if (owningTeam_ == TeamSelected::TEAM_A) {
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
	if (owningTeam_ == TeamSelected::TEAM_B) {
		for (int32 i = 0 < TeamBSpawnPoints.Num(); ++i;)
		{
			int32 Slot = FMath::RandRange(0, TeamBSpawnPoints.Num() - 1);
			if (TeamBSpawnPoints[Slot])
			{
				return TeamBSpawnPoints[Slot];
			}
		}
	}

	if (owningTeam_ == TeamSelected::NONE) {
		for (int32 i = 0 < SpawnPoints.Num(); ++i;)
		{
			int32 Slot = FMath::RandRange(0, SpawnPoints.Num() - 1);
			if (SpawnPoints[Slot])
			{
				return SpawnPoints[Slot];
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
		if (PlayerController->GetPlayerState<ACTF_PlayerState>()->team == TeamSelected::TEAM_A)
		{
			if (APlayerSpawnPoint* SpawnPoint = GetSpawnPoint(TeamSelected::TEAM_A))
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
		if (PlayerController->GetPlayerState<ACTF_PlayerState>()->team == TeamSelected::TEAM_B)
		{
			if (APlayerSpawnPoint* SpawnPoint = GetSpawnPoint(TeamSelected::TEAM_B))
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

		if (PlayerController->GetPlayerState<ACTF_PlayerState>()->team == TeamSelected::NONE)
		{
			if (APlayerSpawnPoint* SpawnPoint = GetSpawnPoint(TeamSelected::NONE))
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