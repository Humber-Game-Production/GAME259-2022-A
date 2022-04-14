// Fill out your copyright notice in the Description page of Project Settings.


#include "CTF_GameState.h"

ACTF_GameState::ACTF_GameState() {
	timeRemaining = teamAScore = teamBScore = numTeamAPlayers = numTeamBPlayers = 0;
	teamAFlagState = teamBFlagState = FlagState::SAFE;

}

void ACTF_GameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACTF_GameState, timeRemaining);
}

void ACTF_GameState::PlayerDied(AMain_Character* deadPlayer_) {
	PlayerKilled.Broadcast(deadPlayer_);
}

void ACTF_GameState::MatchStartCountdownTick() {
	if (ACTF_GameMode* GM = Cast<ACTF_GameMode>(GetWorld()->GetAuthGameMode())) {
		//Start match after warmup timer ends
		if (GetServerWorldTimeSeconds() - warmupStartTime >= GM->warmupTimeLimit) {
			GM->StartMatch();
		}
	}
}

void ACTF_GameState::MatchTick() {
	if (ACTF_GameMode* GM = Cast<ACTF_GameMode>(GetWorld()->GetAuthGameMode())) {
		if (teamAScore >= GM->maxScore) {
			MatchHasEndedUpdate.Broadcast(TeamSelected::TEAM_A);
			GM->EndMatch();
		}
		else if (teamBScore >= GM->maxScore) {
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
		--timeRemaining;
	}
}
