// Fill out your copyright notice in the Description page of Project Settings.


#include "GrenadeComponent.h"
#include "GrenadeActor.h"
#include "Engine/DataTable.h"
#include "BallActor.h"
#include "../Main_Character.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"


UGrenadeComponent::UGrenadeComponent() {

	abilityName = "Grenade";
	cooldown = 1.0f;
	cd_countdown = 0.0f;
	forwardVector = true;
}

bool UGrenadeComponent::TriggerAbilityEffect(){

	UE_LOG(LogTemp, Warning, TEXT("Triggering Ability Effect: %s"), *abilityName.ToString());
	//SpawnGrenadeActor();
	Strafe_Server();
	
	return true;
}

void UGrenadeComponent::Strafe_Server_Implementation()
{
	Strafe_Multicast();
}

bool UGrenadeComponent::Strafe_Server_Validate()
{
	return true;
}

void UGrenadeComponent::Strafe_Multicast_Implementation()
{
	AMain_Character* player = (AMain_Character*)GetOwner();
	if(GetOwner()->HasAuthority())
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

bool UGrenadeComponent::SpawnGrenadeActor()
{
	AMain_Character* Player = (AMain_Character*)GetOwner();
	if (GetOwner()) {
		UDataTable* datatable = Player->GetBallDataTable();
		if (datatable) {
			FBallRow* GrenadeInfo = datatable->FindRow<FBallRow>(FName("Grenade"), TEXT("Grenade"));
			if (GrenadeInfo) {
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.Owner = GetOwner();
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
				FVector spawnLocation = GetOwner()->GetActorLocation() + FVector(100.0f, 100.0f, 0.0f);
				FRotator rotation = GetOwner()->GetActorRotation();

				AGrenadeActor* GrenadeActor = GetWorld()->SpawnActor<AGrenadeActor>(
					AGrenadeActor::StaticClass(),
					spawnLocation, rotation, ActorSpawnParams);

				if (GrenadeActor) {
					GrenadeActor->SphereMesh->SetStaticMesh(GrenadeInfo->ballMesh);
					GrenadeActor->SphereMesh->SetMaterial(0, GrenadeInfo->ballMaterial);
					GrenadeActor->ApplyImpulse(Player->GetFollowCamera()->GetForwardVector() * 5000.f);
				}
			}
		}
	}

	
	
	return true;
}




