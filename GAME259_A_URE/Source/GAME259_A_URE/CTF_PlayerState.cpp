// Fill out your copyright notice in the Description page of Project Settings.


#include "CTF_PlayerState.h"
#include "CTF_GameMode.h"

ACTF_PlayerState::ACTF_PlayerState() {

	/*bIsTeamA = true;
	bReplicates = true;*/
	team = TeamSelected::NONE;
	isCarryingFlag = false;
}

