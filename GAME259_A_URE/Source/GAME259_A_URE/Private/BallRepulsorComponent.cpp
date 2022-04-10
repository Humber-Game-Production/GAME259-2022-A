// Fill out your copyright notice in the Description page of Project Settings.


#include "BallRepulsorComponent.h"
#include "Components/SphereComponent.h"
#include "BallRepulsorActor.h"

UBallRepulsorComponent::UBallRepulsorComponent(){

	abilityName = "BallRepulsor";
	cooldown = 10.0f;
	cd_countdown = 0.0f;

}

void UBallRepulsorComponent::BeginPlay() {
	Super::BeginPlay();
	AddCollisionComp();
}

void UBallRepulsorComponent::AddCollisionComp() {
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.Owner = this->GetOwner();
	FVector spawnLocation = GetOwner()->GetActorLocation();
	FRotator rotation = GetOwner()->GetActorRotation();
	collisionActor = GetWorld()->SpawnActor<ABallRepulsorActor>(
		ABallRepulsorActor::StaticClass(),
		spawnLocation, rotation, ActorSpawnParams);
	collisionActor->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
}

bool UBallRepulsorComponent::TriggerAbilityEffect() {

	if (collisionActor) {
		collisionActor->setSendRequest(true);
		if (collisionActor->getTriggered()) {
			return true;
		}
		else {
			//collisionActor->setSendRequest(false);
		}
	}

	return false;
}


void UBallRepulsorComponent::OnDestroy() {
	collisionActor->Destroy();
}