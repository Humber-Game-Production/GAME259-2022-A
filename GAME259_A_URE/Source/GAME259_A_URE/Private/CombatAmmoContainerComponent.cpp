// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatAmmoContainerComponent.h"

// Sets default values for this component's properties
UCombatAmmoContainerComponent::UCombatAmmoContainerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
	ballInContainer = BallDefault;
	ballNum = 0; 
}

UCombatAmmoContainerComponent::UCombatAmmoContainerComponent(TEnumAsByte<EBallType>  ballInContainer_, int ballNum_)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
	ballInContainer = ballInContainer_;
	ballNum = ballNum_; 
}

// Called when the game starts
void UCombatAmmoContainerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCombatAmmoContainerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//Function used to increase the number of balls, numToIncrease represents the amount of balls to add
void UCombatAmmoContainerComponent::AddNum(int numToIncrease)
{
	ballNum =+ numToIncrease;
}

//Function used to decrease the number of balls, numToDecrease represents the amount of balls to minus
void UCombatAmmoContainerComponent::MinusNum(int numToDecrease)
{
	ballNum =- numToDecrease;
}