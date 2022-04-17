// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BallActor.h"
#include "CombatAmmoContainerComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME259_A_URE_API UCombatAmmoContainerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatAmmoContainerComponent();
	UCombatAmmoContainerComponent(TEnumAsByte<EBallType> ballInContainer_, int ballNum_, int maxBallNum_);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

//May not be needed (Def not needed)
private:	
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Stores the type of ball in the container
	UPROPERTY(EditAnywhere, Category = "Input")
	TEnumAsByte<EBallType> ballInContainer;
	
	//Stores the amount of balls in the container
	UPROPERTY(EditAnywhere, Category = "Input")
	int ballNum;

	//The maximum amount of balls allowed in the container
	UPROPERTY(EditAnywhere, Category = "Input")
	int maxBallNum;

	//Set whether to enable infinite ammo for this container. Meaning balls never run out
	UPROPERTY(EditAnywhere, Category = "Debug\|Cheats")
	bool infiniteAmmo;

	//Set whether to enable manual control over adding or minusing balls for this container
	UPROPERTY(EditAnywhere, Category = "Debug")
	bool manualControl;

	//Set whether to enable debug options
	UPROPERTY(EditAnywhere, Category = "Debug")
	bool Debug;
	
	//Function used to increase the number of balls, numToIncrease represents the amount of balls to add
	UFUNCTION()
	void AddNum(int numToIncrease);

	//Function used to decrease the number of balls, numToDecrease represents the amount of balls to minus
	UFUNCTION()
	void MinusNum(int numToDecrease);
	
	//Function used to manually increase the number of balls
	UFUNCTION()
	void ManualAddNum();

	//Function used to manually increase the number of balls
	UFUNCTION()
	void ManualMinusNum();
	
};