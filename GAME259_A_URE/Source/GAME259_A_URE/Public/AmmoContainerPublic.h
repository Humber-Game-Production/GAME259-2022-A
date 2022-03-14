// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GAME259_A_URE_API AmmoContainerPublic
{
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float ballNum;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class BallActor* ballActor;

public:
	AmmoContainerPublic();
	~AmmoContainerPublic();
};
