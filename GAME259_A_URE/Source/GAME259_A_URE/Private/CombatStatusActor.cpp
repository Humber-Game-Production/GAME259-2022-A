// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatStatusActor.h"
#include "../Main_Character.h"

// Sets default values
ACombatStatusActor::ACombatStatusActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACombatStatusActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACombatStatusActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ACombatStatusActor::setValue(FName statusName_, float durationTime_, float effectAmount_) {
	statusName = statusName_;
	durationTime = durationTime_;
	effectAmount = effectAmount_;
	remainTime = durationTime;
	GetWorldTimerManager().SetTimer(TimeHandle, this, &ACombatStatusActor::ApplyEffect, 1.0f, true);
}

void ACombatStatusActor::ApplyEffect() {
	remainTime--;
	UE_LOG(LogTemp, Warning, TEXT("Remain status time: %f"), remainTime);
	//Remove combatstatus and destroy it when remain time is over
	if (remainTime <= 0.0f) {
		OnCombStatusRemove.Broadcast();
		this->Destroy();
	}
}
