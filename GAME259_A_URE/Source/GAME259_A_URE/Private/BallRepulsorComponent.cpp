// Fill out your copyright notice in the Description page of Project Settings.


#include "BallRepulsorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"
#include "BallRepulsorActor.h"

UBallRepulsorComponent::UBallRepulsorComponent(){

	abilityName = "BallRepulsor";
	cooldown = 10.0f;
	cd_countdown = 0.0f;
	durationTime = 3.0f;

}

void UBallRepulsorComponent::BeginPlay() {
	Super::BeginPlay();
	//GetOwner()->GetWorldTimerManager().SetTimer(CollisionTimeHandle, this,
	//&UBallRepulsorComponent::AddCollisionComp, 2.0f, true);
}

void UBallRepulsorComponent::AddCollisionComp_Multicast_Implementation() {

	if (GetOwner()->HasAuthority()) {
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.Owner = this->GetOwner();
		FVector spawnLocation = GetOwner()->GetActorLocation();
		FRotator rotation = GetOwner()->GetActorRotation();
		collisionActor = GetWorld()->SpawnActor<ABallRepulsorActor>(
			BallRepulsorClass,
			spawnLocation, rotation, ActorSpawnParams);
		collisionActor->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
	}

}


void UBallRepulsorComponent::AddCollisionComp_Server_Implementation() {
	AddCollisionComp_Multicast();
}

bool UBallRepulsorComponent::AddCollisionComp_Server_Validate()
{
	return true;
}

void UBallRepulsorComponent::EndAbility(){

}


bool UBallRepulsorComponent::TriggerAbilityEffect() {

	AddCollisionComp_Server();
	return true;
}


void UBallRepulsorComponent::OnDestroy() {

	if (this->GetOwner()->HasAuthority()) {
		if (IsValid(this->collisionActor)) {
			collisionActor->Destroy();
		}
	}
}
