// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAbilityComponent.h"

// Sets default values for this component's properties
UBaseAbilityComponent::UBaseAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//Set variables
	abilityName = "Default";

	// ...
}


// Called when the game starts
void UBaseAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBaseAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//Implement this in child class
bool UBaseAbilityComponent::TriggerAbilityEffect() {
	return false;
}

void UBaseAbilityComponent::CooldownCountdown() {

	//Reduce cooldown by 1
	if (cd_countdown > 0.0f) {
		cd_countdown--;

		//Get percentage and check when to broadcast the delegate
		float broadcast_percentage = 0.3f; //desired percentage to broadcast
		float cd_percentage = cd_countdown / cooldown; //current cooldown refill percentage
		float percentage_remainder = FMath::Fmod(cd_percentage, broadcast_percentage); //get remainder

		bool broadcast = false;
	
		UE_LOG(LogTemp, Warning, TEXT("Cooldown percentage %f"), percentage_remainder);

		if (cd_countdown <= 0.0f) { //when cooldown is ready
			broadcast = true;
		}
		else if (percentage_remainder == 0.0f) { // when cooldown is at desired percentage
			broadcast = true;
		}
		else if ((broadcast_percentage - KINDA_SMALL_NUMBER) <= percentage_remainder
					&& percentage_remainder <= (broadcast_percentage + KINDA_SMALL_NUMBER)) { // when the float cannot divide properly
			broadcast = true;
		}
		if (broadcast) {
			AbilityCooldownUpdate.Broadcast(abilityName, cd_percentage);
		}

	}
	//Clear timer when the countdown is over
	else {
		//UE_LOG(LogTemp, Warning, TEXT("Clearing Timer"));

		GetOwner()->GetWorldTimerManager().ClearTimer(TimeHandle);
	}


}

void UBaseAbilityComponent::ActivateAbility() {

	if (cd_countdown == 0.0f) {
		//TriggerEffect here
		if (TriggerAbilityEffect()) {
			cd_countdown = cooldown;
			//Get the timer from the attached actor
			AbilityCooldownUpdate.Broadcast(abilityName, 0.0f);
			GetOwner()->GetWorldTimerManager().SetTimer(TimeHandle, this,
				&UBaseAbilityComponent::CooldownCountdown, 1.0f, true);
		}

	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("Ability %s in cooldown"), *abilityName.ToString());

	}


}


