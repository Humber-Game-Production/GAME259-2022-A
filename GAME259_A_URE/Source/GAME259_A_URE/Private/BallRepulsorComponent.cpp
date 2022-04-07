// Fill out your copyright notice in the Description page of Project Settings.


#include "BallRepulsorComponent.h"
#include "Components/SphereComponent.h"
#include "BallRepulsorActor.h"

UBallRepulsorComponent::UBallRepulsorComponent(){

	//Sets the default collision profile to "Projectile" profile
	//SphereComp->SetCollisionProfileName(TEXT("OverlapAll"));
	//SphereComp->SetIsReplicated(true);
	abilityName = "BallRepulsor";
	cooldown = 10.0f;
	cd_countdown = 0.0f;
}



void UBallRepulsorComponent::BeginPlay() {
	Super::BeginPlay();

	if (GetOwner()->HasAuthority()) {
		AddCollisionComp();
	}

}

void UBallRepulsorComponent::AddCollisionComp_Implementation() {
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.Owner = this->GetOwner();
	FVector spawnLocation = GetOwner()->GetActorLocation();
	FRotator rotation = GetOwner()->GetActorRotation();
	collisionActor = GetWorld()->SpawnActor<ABallRepulsorActor>(
		ABallRepulsorActor::StaticClass(),
		spawnLocation, rotation, ActorSpawnParams);
	collisionActor->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
}

bool UBallRepulsorComponent::TriggerAbilityEffect(){

	UE_LOG(LogTemp, Warning, TEXT("Triggering Ability Effect: %s"), *abilityName.ToString());
	collisionActor->setSendRequest(true);
	UE_LOG(LogTemp, Warning, TEXT("Triger BallRepulsor status: %s"), (collisionActor->getTriggered() ? TEXT("true") : TEXT("false")));

	if (collisionActor->getTriggered()) {
		return true;
	}
	else {
		//collisionActor->setSendRequest(false);
	}

	return false;
}


void UBallRepulsorComponent::OnDestroy(){
	collisionActor->Destroy();
}