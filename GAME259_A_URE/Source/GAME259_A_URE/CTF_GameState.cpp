// Fill out your copyright notice in the Description page of Project Settings.


#include "CTF_GameState.h"

ACTF_GameState::ACTF_GameState() {
	timeRemaining = teamAScore = teamBScore = teamARoundsWon = teamBRoundsWon = numTeamAPlayers = numTeamBPlayers = 0;
	teamAFlagState = teamBFlagState = FlagState::SAFE;
	isOvertime = false;


}

void ACTF_GameState::PlayerDied(AMain_Character* deadPlayer_) {
	PlayerKilled.Broadcast(deadPlayer_);
}

void ACTF_GameState::MatchStartCountdownTick() {
	SetReplicates(true);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "MatchStartCountdownTick replicates true");

	if (ACTF_GameMode* GM = Cast<ACTF_GameMode>(GetWorld()->GetAuthGameMode())) {
		if (GetServerWorldTimeSeconds() - warmupStartTime >= GM->warmupTimeLimit) {
			GM->StartMatch();
		}
	}
}

void ACTF_GameState::MatchTick() {
	SetReplicates(true);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "match tick replicates true");

	if (ACTF_GameMode* GM = Cast<ACTF_GameMode>(GetWorld()->GetAuthGameMode())) {
		if (teamAScore >= GM->maxScore) {
			FString winMessage = FString::Printf(TEXT("Team A Wins!"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, winMessage);
			MatchHasEndedUpdate.Broadcast(TeamSelected::TEAM_A);
			GM->EndMatch();
		}
		else if (teamBScore >= GM->maxScore) {
			FString winMessage = FString::Printf(TEXT("Team B Wins!"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, winMessage);
			MatchHasEndedUpdate.Broadcast(TeamSelected::TEAM_B);
			GM->EndMatch();
		}
		if (timeRemaining <= 0) {
			if (teamAScore == teamBScore) {
			MatchHasEndedUpdate.Broadcast(TeamSelected::NONE);
			GM->EndMatch();
			}
			else if (teamAScore > teamBScore) {
				MatchHasEndedUpdate.Broadcast(TeamSelected::TEAM_A);
				GM->EndMatch();
			}
			else {
				MatchHasEndedUpdate.Broadcast(TeamSelected::TEAM_B);
				GM->EndMatch();
			}
		}
		MatchTimeRemainingUpdate.Broadcast(timeRemaining);
		FString timeRemainingMessage = FString::Printf(TEXT("%d"), timeRemaining);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, timeRemainingMessage);
		--timeRemaining;
	}
}