// Fill out your copyright notice in the Description page of Project Settings.


#include "CTF_PlayerState.h"
#include "CTF_GameMode.h"

ACTF_PlayerState::ACTF_PlayerState() {

	/*bIsTeamA = true;
	bReplicates = true;*/
	team = TeamSelected::NONE;
	isCarryingFlag = false;
}

void ACTF_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACTF_PlayerState, team);
	DOREPLIFETIME(ACTF_PlayerState, isCarryingFlag);
}

