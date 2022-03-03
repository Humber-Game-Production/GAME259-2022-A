// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerStats.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Components/ActorComponent.h"
// Sets default values for this component's properties
UPlayerStatsComponent::UPlayerStatsComponent()
{
	/*Hunger = 100.0f;
	HungerDecrementValue = 0.5f;
	Thirst = 100.0f;
	ThirstDecrementValue = 0.5f;*/
	Health = 30.0f;
	//	Stamina = 100.0f;

}


// Called when the game starts
void UPlayerStatsComponent::BeginPlay()
{
	Super::BeginPlay();
	SetIsReplicated(true);

	//if (GetOwnerRole() == ROLE_Authority)
	//{
	//	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UPlayerStatsComponent::HandleHungerAndThirst, 3.0f, true);
	//	GetWorld()->GetTimerManager().SetTimer(StaminaHandle, this, &UPlayerStatsComponent::RegenerateStamina, 1.0f, true);//Regenerate stamina
	//}
}

void UPlayerStatsComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UPlayerStatsComponent, Health);
	/*replicates to everyone
	DOREPLIFETIME(UPlayerStatsComponent, Hunger);
	DOREPLIFETIME(UPlayerStatsComponent, Thirst);
	DOREPLIFETIME(UPlayerStatsComponent, Stamina);*/

}

//void UPlayerStatsComponent::HandleHungerAndThirst()
//{
//	if (GetOwnerRole() == ROLE_Authority)
//	{
//		LowerHunger(HungerDecrementValue);
//		LowerThirst(ThirstDecrementValue);
//	}
//}
//
//
//bool UPlayerStatsComponent::ServerLowerHunger_Validate(float value)
//{
//	return true;
//}
//
//void UPlayerStatsComponent::ServerLowerHunger_Implementation(float value)
//{
//	if (GetOwnerRole() == ROLE_Authority)
//	{
//		LowerHunger(value);
//	}
//}
//
//
//bool UPlayerStatsComponent::ServerLowerThirst_Validate(float value)
//{
//	return true;
//}
//
//void UPlayerStatsComponent::ServerLowerThirst_Implementation(float value)
//{
//	if (GetOwnerRole() == ROLE_Authority)
//	{
//		LowerThirst(value);
//	}
//}
//
//void UPlayerStatsComponent::LowerHunger(float value)
//{
//	if (GetOwnerRole() < ROLE_Authority)
//	{
//		ServerLowerHunger(value);
//	}
//	else if (GetOwnerRole() == ROLE_Authority)
//	{
//		Hunger -= value;
//	}
//}
//
//void UPlayerStatsComponent::LowerThirst(float value)
//{
//	if (GetOwnerRole() < ROLE_Authority)
//	{
//		ServerLowerThirst(value);
//	}
//	else if (GetOwnerRole() == ROLE_Authority)
//	{
//		Thirst -= value;
//	}
//}
//
//void UPlayerStatsComponent::LowerStamina(float value)
//{
//	if (GetOwnerRole() < ROLE_Authority)
//	{
//		ServerLowerStamina(value);
//	}
//	else if (GetOwnerRole() == ROLE_Authority)
//	{
//		Stamina -= value;
//	}
//}

void UPlayerStatsComponent::LowerHealth(float value)
{
	if (GetOwnerRole() < ROLE_Authority)
	{
		ServerLowerHealth(value);
	}
	else if (GetOwnerRole() == ROLE_Authority)
	{
		Health -= value;
		if (Health < 0.0f)
			Health = 0.0f;
	}
}

bool UPlayerStatsComponent::ServerLowerHealth_Validate(float value)
{
	return true;
}
void UPlayerStatsComponent::ServerLowerHealth_Implementation(float value)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		LowerHealth(value);
	}
}
//bool UPlayerStatsComponent::ServerLowerStamina_Validate(float value)
//{
//	return true;
//}
//void UPlayerStatsComponent::ServerLowerStamina_Implementation(float value)
//{
//	if (GetOwnerRole() == ROLE_Authority)
//	{
//		LowerStamina(value);
//	}
//}
//void UPlayerStatsComponent::RegenerateStamina()
//{
//	if (GetOwnerRole() < ROLE_Authority)
//	{
//		if (Stamina > 100.0f)
//		{
//		Stamina = 100.0f;
//		}
//	}
//
//	else 
//	{
//		++Stamina;
//	}
//}
//float UPlayerStatsComponent::GetHunger()
//{
//	return Hunger;
//}
//
//
//
//float UPlayerStatsComponent::GetThirst()
//{
//	return Thirst;
//}
//
//float UPlayerStatsComponent::GetStamina()
//{
//	return Stamina;
//}

float UPlayerStatsComponent::GetHealth()
{
	return Health;
}

//void UPlayerStatsComponent::ControlSprintingTimer(bool IsSprinting)
//{
//	if (IsSprinting)
//	{
//		GetWorld()->GetTimerManager().PauseTimer(StaminaHandle);
//	}
//	else
//	{
//		GetWorld()->GetTimerManager().UnPauseTimer(StaminaHandle);
//	}
//}

