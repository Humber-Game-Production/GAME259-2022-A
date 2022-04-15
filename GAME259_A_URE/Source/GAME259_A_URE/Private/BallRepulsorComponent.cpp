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

void UBallRepulsorComponent::EndAbility(){
	//collisionActor->setSendRequest(false);
	//GetOwner()->GetWorldTimerManager().ClearTimer(AbilityTimeHandle);
	//if (this->GetOwner()->HasAuthority()) {
	//	if (IsValid(this->collisionActor)) {
	//		collisionActor->Destroy();
	//	}
	//}
	//OnDestroy_Server(collisionActor);
}


bool UBallRepulsorComponent::TriggerAbilityEffect() {

	AddCollisionComp_Server();
	if (collisionActor) {
		//collisionActor->setSendRequest(true);
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, FString::Printf(TEXT("Toggle visibility")));
		//GetOwner()->GetWorldTimerManager().SetTimer(AbilityTimeHandle, this,
		//	&UBallRepulsorComponent::EndAbility, durationTime, true);
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

void UBallRepulsorComponent::OnDestroy_Multicast_Implementation(ABallRepulsorActor* collisionActor_) {

	if (this->GetOwner()->HasAuthority()) {
		if (IsValid(collisionActor_)) {
			collisionActor_->Destroy();
		}
	}
}

void UBallRepulsorComponent::OnDestroy_Server_Implementation(ABallRepulsorActor* collisionActor_) {

	OnDestroy_Multicast(collisionActor_);
}