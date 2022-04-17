// Copyright Epic Games, Inc. All Rights Reserved.

#include "CTF_GameMode.h"
#include "Main_Character.h"
#include "GameFramework/SpectatorPawn.h"
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

	//These defaults may be changed in CTF_GameMode
	matchTimeLimit = 1000.0f;
	warmupTimeLimit = 10.0f;
	maxScore = 3;
	maxPlayers = 4;

	//maxRounds = 3;    //not used at this point
	//respawnDelay = 5.0f;   //currently not used, would require coordination with UI respawn widget to have dynamic respawnDelay

	//Enables WaitingToStart Match State
	bDelayedStart = true;

	bUseSeamlessTravel = true;
}

void ACTF_GameMode::HandleMatchIsWaitingToStart() {

	Super::HandleMatchIsWaitingToStart();

	//TODO: check if this is a restarted game somehow, setup warmup timer outside post login

	UClass* SpawnPointClass = APlayerSpawnPoint::StaticClass();

	//Get all the spawn points and organize them based on team
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
	MatchWaitingToStart();
}
 
void ACTF_GameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (AMain_PlayerController* PlayerController = Cast<AMain_PlayerController>(NewPlayer))
	{
		//if players.Num >= max players, NewPlayer forced spectator 
		if (Players.Num() >= maxPlayers) {
			if (ACTF_PlayerState* PlayerState = Cast<ACTF_PlayerState>(NewPlayer->PlayerState)) {
				PlayerState->SetIsSpectator(true);
				PlayerState->isSpectator_CTF = true;
				if (!GetMatchState().IsEqual("WaitingToStart")) {
					PlayerController->GetPawn()->Destroy();
				}
				Spawn(PlayerController);
				Spectators.Add(PlayerController);
			}
			return;
		}
		else {
			Players.Add(PlayerController);
		}
	}
}

void ACTF_GameMode::PlayerJoinedTeam() 
{
	if (ACTF_GameState* GS = Cast<ACTF_GameState>(GetWorld()->GetGameState())) {
		if (GS->numTeamAPlayers + GS->numTeamBPlayers < maxPlayers) {
			return;
		}
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
		//Start match timer and set up 1 second match tick
		GetWorldTimerManager().SetTimer(GS->MatchTimer, GS, &ACTF_GameState::MatchTick, 1.0f, true, 0.0f);
		GS->matchStartTime = GS->GetServerWorldTimeSeconds();
		GS->timeRemaining = matchTimeLimit;
		//Spawn all the players as match start
		for (AMain_PlayerController* PC : Players) {
			if (AMain_Character* Character = Cast<AMain_Character>(PC->GetPawn())) {
				//Player is not dead when match starts
				if (Character->GetCurrentHealth() > 0) {
					Character->DeathEvent();
					Character->On_Destroy();
					Character->Destroy();
				}
				//Player is dead when match starts
				else {
					GetWorld()->GetTimerManager().ClearTimer(PC->RespawnHandle);
				}
				Spawn(PC);
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
		//Clean up match timer
		GetWorld()->GetTimerManager().ClearTimer(GS->MatchTimer);
		GS->MatchTimer.Invalidate();
		
	}
}

void ACTF_GameMode::Logout(AController* Exiting)
{
	if (AMain_PlayerController* PlayerController = Cast<AMain_PlayerController>(Exiting)) {
		if (Players.Contains(Exiting)) {
			if (ACTF_PlayerState* PS = Cast<ACTF_PlayerState>(PlayerController->PlayerState)) {
				if (PS->team == TeamSelected::TEAM_A) {
					if (ACTF_GameState* GS = Cast<ACTF_GameState>(GetWorld()->GetGameState())) {
						GS->numTeamAPlayers -= 1;
						GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, TEXT("Reduce team players"));
						GS->PlayerDied(PlayerController);
						GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, TEXT("Player died call"));
					}
				}
				else if (PS->team == TeamSelected::TEAM_B) {
					if (ACTF_GameState* GS = Cast<ACTF_GameState>(GetWorld()->GetGameState())) {
						GS->numTeamBPlayers -= 1;
						GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, TEXT("Reduce team players"));
						GS->PlayerDied(PlayerController);
						GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, TEXT("Player died call"));
					}
				}
			}
			Players.Remove(PlayerController);
		}
		else if (Spectators.Contains(Exiting)) {
			Spectators.Remove(PlayerController);
		}
		Super::Logout(Exiting);
	}
}

void ACTF_GameMode::Respawn(AController* Controller)
{
	if (AMain_PlayerController* PlayerController = Cast<AMain_PlayerController>(Controller))
	{
		FTimerDelegate RespawnDele;
		RespawnDele.BindUFunction(this, FName("Spawn"), PlayerController);
		GetWorld()->GetTimerManager().SetTimer(PlayerController->RespawnHandle, RespawnDele, 3.0f, false);
	}
}

APlayerSpawnPoint* ACTF_GameMode::GetSpawnPoint(TeamSelected owningTeam_)
{
	//Gets the total teamA spawn points
	if (owningTeam_ == TeamSelected::TEAM_A) {
		//Attempt to find an unobstructed spawn 5 times, if it fails return nullptr
		for (int i = 0; i < 5; ++i)
		{
			//Choose a random teamA spawn point
			int32 Slot = FMath::RandRange(0, TeamASpawnPoints.Num() - 1);
			if (TeamASpawnPoints[Slot])
			{
				//Check if spawn point obstructed
				if (!TeamASpawnPoints[Slot]->obstructed) {
					return TeamASpawnPoints[Slot];
				}
			}
		}
		return nullptr;
	}
	//Gets the total teamB spawn points
	if (owningTeam_ == TeamSelected::TEAM_B) {
		//Attempt to find an unobstructed spawn 5 times, if it fails return nullptr
		for (int i = 0; i < 5; ++i)
		{
			//Choose a random teamB spawn point
			int32 Slot = FMath::RandRange(0, TeamBSpawnPoints.Num() - 1);
			if (TeamBSpawnPoints[Slot])
			{
				//Check if spawn point obstructed
				if (!TeamBSpawnPoints[Slot]->obstructed) {
					return TeamBSpawnPoints[Slot];
				}
			}
		}
		return nullptr;
	}
	//Not currently used for any gameplay reasons
	//Gets the total spawn spoints with team set to none
	if (owningTeam_ == TeamSelected::NONE) {
		//Attempt to find an unobstructed spawn 5 times, if it fails return nullptr
		for (int i = 0; i < 5; ++i)
		{
			//Choose a random team none spawn point
			int32 Slot = FMath::RandRange(0, SpawnPoints.Num() - 1);
			if (SpawnPoints[Slot])
			{
				//Check if spawn point obstructed
				if (!SpawnPoints[Slot]->obstructed) {
					return SpawnPoints[Slot];
				}
			}
		}
		return nullptr;
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
			//Check if an unobstructed spawn point was found
			if (APlayerSpawnPoint* SpawnPoint = GetSpawnPoint(TeamSelected::TEAM_A))
			{
				FVector LocationOffset = FVector(0.0f, 0.0f, 0.0f);
				FVector Location = SpawnPoint->GetActorLocation() + LocationOffset;
				FRotator Rotation = SpawnPoint->GetActorRotation();
				if (APawn* Pawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, Location, Rotation))
				{
					PlayerController->Possess(Pawn);
				}
			}
			//Create timer to try again in 1 second
			else {
				FTimerDelegate RespawnDele;
				FTimerHandle RespawnHandle;
				RespawnDele.BindUFunction(this, FName("Spawn"), PlayerController);
				GetWorld()->GetTimerManager().SetTimer(RespawnHandle, RespawnDele, 1.0f, false);
			}
		}
		//Team B Spawn
		if (PlayerController->GetPlayerState<ACTF_PlayerState>()->team == TeamSelected::TEAM_B)
		{
			//Check if an unobstructed spawn point was found
			if (APlayerSpawnPoint* SpawnPoint = GetSpawnPoint(TeamSelected::TEAM_B))
			{
				FVector LocationOffset = FVector(0.0f, 0.0f, 0.0f);
				FVector Location = SpawnPoint->GetActorLocation() + LocationOffset;
				FRotator Rotation = SpawnPoint->GetActorRotation();
				if (APawn* Pawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, Location, Rotation))
				{
					PlayerController->ClientSetRotation(Rotation);
					PlayerController->Possess(Pawn);
				}
			}
			//Create timer to try again in 1 second
			else {
				FTimerDelegate RespawnDele;
				FTimerHandle RespawnHandle;
				RespawnDele.BindUFunction(this, FName("Spawn"), PlayerController);
				GetWorld()->GetTimerManager().SetTimer(RespawnHandle, RespawnDele, 1.0f, false);
			}
		}

		if (PlayerController->GetPlayerState<ACTF_PlayerState>()->team == TeamSelected::NONE)
		{
			//Check if an unobstructed spawn point was found
			if (APlayerSpawnPoint* SpawnPoint = GetSpawnPoint(TeamSelected::NONE))
			{
				FVector LocationOffset = FVector(0.0f, 0.0f, 0.0f);
				FVector Location = SpawnPoint->GetActorLocation() + LocationOffset;
				FRotator Rotation = SpawnPoint->GetActorRotation();
				if (APawn* Pawn = GetWorld()->SpawnActor<APawn>(SpectatorClass, Location, Rotation))
				{
					PlayerController->Possess(Pawn);
				}
			}
			//Create timer to try again in 1 second
			else {
				FTimerDelegate RespawnDele;
				FTimerHandle RespawnHandle;
				RespawnDele.BindUFunction(this, FName("Spawn"), PlayerController);
				GetWorld()->GetTimerManager().SetTimer(RespawnHandle, RespawnDele, 1.0f, false);
			}
		}
	}
}