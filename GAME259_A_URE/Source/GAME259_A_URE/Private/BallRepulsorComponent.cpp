// Fill out your copyright notice in the Description page of Project Settings.


#include "BallRepulsorComponent.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"
#include "BallRepulsorActor.h"

UBallRepulsorComponent::UBallRepulsorComponent(){

	abilityName = "BallRepulsor";
	cooldown = 10.0f;
	cd_countdown = 0.0f;

}

void UBallRepulsorComponent::BeginPlay() {
	Super::BeginPlay();
	GetOwner()->GetWorldTimerManager().SetTimer(CollisionTimeHandle, this,
		&UBallRepulsorComponent::AddCollisionComp, 2.0f, true);
}

void UBallRepulsorComponent::AddCollisionComp_Implementation() {

	if (GetOwner()->HasAuthority()) {
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.Owner = this->GetOwner();
		FVector spawnLocation = GetOwner()->GetActorLocation();
		FRotator rotation = GetOwner()->GetActorRotation();
		collisionActor = GetWorld()->SpawnActor<ABallRepulsorActor>(
			ABallRepulsorActor::StaticClass(),
			spawnLocation, rotation, ActorSpawnParams);
		collisionActor->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
		GetOwner()->GetWorldTimerManager().ClearTimer(CollisionTimeHandle);
	}

}


void UBallRepulsorComponent::EndAbility(){
	collisionActor->setSendRequest(false);
	GetOwner()->GetWorldTimerManager().ClearTimer(AbilityTimeHandle);
}


bool UBallRepulsorComponent::TriggerAbilityEffect() {

	if (collisionActor) {
		collisionActor->setSendRequest(true);
		GetOwner()->GetWorldTimerManager().SetTimer(AbilityTimeHandle, this,
			&UBallRepulsorComponent::EndAbility, 3.0f, true);
	}

	return true;
}


void UBallRepulsorComponent::OnDestroy() {

	if (this->GetOwner()->HasAuthority()) {
		if (IsValid(this->collisionActor)) {
			collisionActor->Destroy();
		}
	}
}