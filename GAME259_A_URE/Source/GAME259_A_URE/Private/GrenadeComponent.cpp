// Fill out your copyright notice in the Description page of Project Settings.


#include "GrenadeComponent.h"

UGrenadeComponent::UGrenadeComponent() {

	abilityName = "Grenade";
	cooldown = 6.0f;
	cd_countdown = 0.0f;
}

bool UGrenadeComponent::TriggerAbilityEffect(){

	UE_LOG(LogTemp, Warning, TEXT("Triggering Ability Effect: %s"), *abilityName.ToString());
	return false;
}
