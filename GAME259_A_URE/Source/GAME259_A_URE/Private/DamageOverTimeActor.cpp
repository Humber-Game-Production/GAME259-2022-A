// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageOverTimeActor.h"
#include "../Main_Character.h"

ADamageOverTimeActor::ADamageOverTimeActor(){}




void ADamageOverTimeActor::ApplyEffect(){


	if (IsValid(this)) {
		//UE_LOG(LogTemp, Warning, TEXT("This is a DOT actor."));
		AMain_Character* player = (AMain_Character*)this->GetOwner();
		//Let player take damage
		if (player) {
			player->TakeDamage(effectAmount, FDamageEvent(), nullptr, this);
		}
		Super::ApplyEffect();
	}
	
}
