// Fill out your copyright notice in the Description page of Project Settings.


#include "StrafeComponent.h"
#include "../Main_Character.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"


UStrafeComponent::UStrafeComponent() {

	abilityName = "Strafe";
	cooldown = 1.0f;
	cd_countdown = 0.0f;
	forwardVector = true;
}

bool UStrafeComponent::TriggerAbilityEffect() {

	UE_LOG(LogTemp, Warning, TEXT("Triggering Ability Effect: %s"), *abilityName.ToString());
	//SpawnGrenadeActor();
	Strafe_Server();

	return true;
}

void UStrafeComponent::Strafe_Server_Implementation()
{
	Strafe_Multicast();
}

bool UStrafeComponent::Strafe_Server_Validate()
{
	return true;
}

void UStrafeComponent::Strafe_Multicast_Implementation()
{
	AMain_Character* player = (AMain_Character*)GetOwner();
	if (GetOwner()->HasAuthority())
	{
		if (forwardVector) {
			player->GetCharacterMovement()->AddImpulse(player->GetActorForwardVector() * 700.0f, true);
		}
		else {
			FVector direction = player->GetFollowCamera()->GetComponentRotation().Vector();
			float movement_x = direction.X * 700.0f;
			float movement_y = direction.Y * 700.0f;
			float movement_z = direction.Z * 250.0f;
			player->GetCharacterMovement()->AddImpulse(FVector(movement_x, movement_y, movement_z), true);
		}
	}
}
