// Fill out your copyright notice in the Description page of Project Settings.


#include "CTF_GameState.h"

ACTF_GameState::ACTF_GameState() {


}

void ACTF_GameState::MatchStartCountdownTick() {
	if (ACTF_GameMode* GM = Cast<ACTF_GameMode>(GetWorld()->GetAuthGameMode())) {
		if (GetServerWorldTimeSeconds() - warmupStartTime >= GM->warmupTimeLimit) {
			GM->StartMatch();
		}
	}
}

void ACTF_GameState::MatchTick() {
	if (ACTF_GameMode* GM = Cast<ACTF_GameMode>(GetWorld()->GetAuthGameMode())) {
		if (GetServerWorldTimeSeconds() - matchStartTime >= GM->matchTimeLimit) {
			GM->RestartGame();
		}
		int timeRemaining = GM->matchTimeLimit - (GetServerWorldTimeSeconds() - matchStartTime) + 1;
		MatchTimeRemainingUpdate.Broadcast(timeRemaining);
	}
}