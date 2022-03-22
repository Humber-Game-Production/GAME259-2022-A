// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageOverTimeActor.h"
#include "../Main_Character.h"

ADamageOverTimeActor::ADamageOverTimeActor(){}




void ADamageOverTimeActor::ApplyEffect(){
	Super::ApplyEffect();
	UE_LOG(LogTemp, Warning, TEXT("This is a DOT actor."));
	AMain_Character *player = (AMain_Character*)this->GetOwner();
	//Let player take damage
	if (player) {
		UE_LOG(LogTemp, Warning, TEXT("Player taking damage."));
		player->TakeDamage(effectAmount, FDamageEvent(), nullptr, this);
	}

}
