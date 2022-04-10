// Fill out your copyright notice in the Description page of Project Settings.


#include "GrenadeComponent.h"
#include "../Main_Character.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"

UGrenadeComponent::UGrenadeComponent() {

	abilityName = "Grenade";
	cooldown = 6.0f;
	cd_countdown = 0.0f;
}

bool UGrenadeComponent::TriggerAbilityEffect(){

	UE_LOG(LogTemp, Warning, TEXT("Triggering Ability Effect: %s"), *abilityName.ToString());
	AMain_Character* player = (AMain_Character*)GetOwner();
	player->GetCharacterMovement()->AddImpulse(player->GetFollowCamera()->GetComponentRotation().Vector() * 4000.0f, true);
	
	return true;
}
