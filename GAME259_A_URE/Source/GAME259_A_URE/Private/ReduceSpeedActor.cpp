// Fill out your copyright notice in the Description page of Project Settings.


#include "ReduceSpeedActor.h"
#include "../Main_Character.h"

AReduceSpeedActor::AReduceSpeedActor(){}


void AReduceSpeedActor::ApplyEffect() {

	AMain_Character* player = (AMain_Character*)this->GetOwner();
	//Set player velocity
	if (player) {
		player->setVelocity(1.0f - effectAmount);
	}

	remainTime--;
	//Remove combatstatus and destroy it when remain time is over
	if (remainTime <= 0.0f) {
		player->resetVelocity();
		OnCombStatusRemove.Broadcast(this);
		Destroy();
	}

}