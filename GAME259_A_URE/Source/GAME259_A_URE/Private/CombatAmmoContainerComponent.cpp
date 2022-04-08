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
	maxBallNum = 0;

	//Set whether to enable debug options
	Debug = false;
	infiniteAmmo = false;
	manualControl = false;
}

UCombatAmmoContainerComponent::UCombatAmmoContainerComponent(TEnumAsByte<EBallType>  ballInContainer_, int ballNum_, int maxBallNum_)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
	ballInContainer = ballInContainer_;
	ballNum = ballNum_;
	maxBallNum = maxBallNum_;

	//Set whether to enable debug options
	Debug = false;
	infiniteAmmo = false;
	manualControl = false;
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

	//If true the container will never run out of balls
	if (infiniteAmmo == true)
	{
		ballNum = 99;
		if (Debug == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, TEXT("> Infinite ammo is enabled"));
		}
	}

	//Enables debug options for testing
	if (Debug == true)
	{
		//Displays the max number of balls allowed inside the container
		GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Yellow, TEXT("> Max number of balls allowed in the container: " + FString::FromInt(maxBallNum) ));
		//Displays the current number of balls inside the container
		GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Blue, TEXT("> Number of balls in the container: " + FString::FromInt(ballNum) ));
		//Displays the type of ball inside the container
		GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Green, TEXT("> Ball In container: " + UEnum::GetDisplayValueAsText(ballInContainer).ToString() ));
		//Displays the type of actor running the debug option
		GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Orange, TEXT("Debug options enabled for: " + this->GetFName().ToString()));
		
	}
	
}

//Function used to increase the number of balls, numToIncrease represents the amount of balls to add
void UCombatAmmoContainerComponent::AddNum(int numToIncrease)
{
	ballNum = ballNum + numToIncrease;
	UE_LOG(LogTemp, Warning, TEXT("BallDefault: %d"), ballNum);


	if (maxBallNum != 0)
	{
		if ((ballNum > maxBallNum) && (infiniteAmmo == false))
		{
			ballNum = maxBallNum;
		}
	}
	if (Debug == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, TEXT("Ball Added") );
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, TEXT("> Number of balls in the container: " + FString::FromInt(ballNum) ));
	}
	
}

//Function used to decrease the number of balls, numToDecrease represents the amount of balls to minus
void UCombatAmmoContainerComponent::MinusNum(int numToDecrease)
{
	ballNum = ballNum - numToDecrease;
	if (ballNum < 0)
	{
		ballNum = 0;
	}
	if (Debug == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, TEXT("Ball Removed") );
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, TEXT("> Number of balls in the container: " + FString::FromInt(ballNum) ));
	}
}

//Function used to manually increase the number of balls
void UCombatAmmoContainerComponent::ManualAddNum()
{
	if (manualControl == true)
	{
		AddNum(1);
		if (Debug == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Magenta, TEXT("Ball Added Manually") );
		}
	}
	
}

//Function used to manually decrease the number of balls
void UCombatAmmoContainerComponent::ManualMinusNum()
{
	if (manualControl == true)
	{
		MinusNum(1);
		if (Debug == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Magenta, TEXT("Ball Removed Manually") );
		}
	}
	
}