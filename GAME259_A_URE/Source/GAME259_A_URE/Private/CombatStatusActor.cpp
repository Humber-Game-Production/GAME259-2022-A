// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatStatusActor.h"
#include "../Main_Character.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ACombatStatusActor::ACombatStatusActor(){

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle Effect"));
	RootComponent = ParticleComponent;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ACombatStatusActor::BeginPlay(){

	Super::BeginPlay();
}

// Called every frame
void ACombatStatusActor::Tick(float DeltaTime){

	Super::Tick(DeltaTime);
	
}

void ACombatStatusActor::setValue(FName statusName_, float durationTime_, float effectAmount_, 
	UParticleSystem* particleEffect_, FString description_, UTexture2D* icon_)
{
	statusName = statusName_;
	durationTime = durationTime_;
	effectAmount = effectAmount_;
	ParticleComponent->SetTemplate(particleEffect_);
	ParticleComponent->SetIsReplicated(false);
	description = description_;
	icon = icon_;
	remainTime = durationTime;
	GetWorldTimerManager().SetTimer(TimeHandle, this, &ACombatStatusActor::ApplyEffect, 1.0f, true);
	
}

void ACombatStatusActor::OnDestroy_Server_Implementation()
{
	OnDestroy_Multicast();
}

void ACombatStatusActor::ApplyEffect() {}

void ACombatStatusActor::OnDestroy_Multicast_Implementation() {
	Destroy();
}