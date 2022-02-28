// Fill out your copyright notice in the Description page of Project Settings.


#include "BallFireActor.h"

ABallFireActor::ABallFireActor()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> SphereMaterialAsset(TEXT("/Game/Materials/BallFireMat.BallFireMat"));
	if (SphereMaterialAsset.Succeeded())
	{
		SphereMesh->SetMaterial(0, SphereMaterialAsset.Object);
	}

	//Determines if the actor has a status effect or not
	HasStatus = true;

	//The type of status to apply
	Status = "Fire";
	
}

