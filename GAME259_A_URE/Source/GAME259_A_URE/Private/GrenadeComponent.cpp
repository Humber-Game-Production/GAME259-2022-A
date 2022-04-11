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
	cooldown = 6.0f;
	cd_countdown = 0.0f;
}

bool UGrenadeComponent::TriggerAbilityEffect(){

	UE_LOG(LogTemp, Warning, TEXT("Triggering Ability Effect: %s"), *abilityName.ToString());
	//AMain_Character* player = (AMain_Character*)GetOwner();
	//player->GetCharacterMovement()->AddImpulse(player->GetFollowCamera()->GetComponentRotation().Vector() * 4000.0f, true);
	SpawnGrenadeActor();
	return true;
}

bool UGrenadeComponent::SpawnGrenadeActor()
{
	UE_LOG(LogTemp, Warning, TEXT("Spawn Grenade Actor!"));
	AMain_Character* Player = (AMain_Character*)GetOwner();
	if (GetOwner()) {
		UE_LOG(LogTemp, Warning, TEXT("player works!"));
	}
	UDataTable* datatable = Player->GetBallDataTable();
	if (datatable) {
		UE_LOG(LogTemp, Warning, TEXT("it works!"));
		FBallRow* GrenadeInfo = datatable->FindRow<FBallRow>(FName("Grenade"), TEXT("Grenade"));
		if (GrenadeInfo) {
			UE_LOG(LogTemp, Warning, TEXT("table works!"));
		}
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.Owner = GetOwner();
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		FVector spawnLocation = GetOwner()->GetActorLocation() + FVector(100.0f,100.0f,0.0f);
		
			UE_LOG(LogTemp, Warning, TEXT("Location %f %f %f"), spawnLocation.X, spawnLocation.Y,spawnLocation.Z);
		
		//FVector spawnLocation = FVector(0.0f,0.0f,0.0f);
		FRotator rotation = GetOwner()->GetActorRotation();
		
		AGrenadeActor* GrenadeActor = GetWorld()->SpawnActor<AGrenadeActor>(
			AGrenadeActor::StaticClass(),
			spawnLocation, rotation, ActorSpawnParams);
		
		if (GrenadeActor) {
			UE_LOG(LogTemp, Warning, TEXT("mesh works!"));
			GrenadeActor->SphereMesh->SetStaticMesh(GrenadeInfo->ballMesh);
			GrenadeActor->SphereMesh->SetMaterial(0, GrenadeInfo->ballMaterial);
			GrenadeActor->ApplyImpulse(Player->GetFollowCamera()->GetForwardVector() * 5000.f);
		}
		
	}
	
	
	return true;
}
