// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatStatusComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UCombatStatusComponent::UCombatStatusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCombatStatusComponent::BeginPlay()
{
	Super::BeginPlay();

	
	//GetWorldTimerManager().SetTimer(TimeHandle, this, &UCombatStatusComponent::ApplyEffect, durationTime);

}


// Called every frame
void UCombatStatusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

