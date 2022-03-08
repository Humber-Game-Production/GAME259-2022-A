// Fill out your copyright notice in the Description page of Project Settings.


#include "BallIceActor.h"

ABallIceActor::ABallIceActor()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> SphereMaterialAsset(TEXT("/Game/Materials/BallIceMat.BallIceMat"));
	if (SphereMaterialAsset.Succeeded())
	{
		SphereMesh->SetMaterial(0, SphereMaterialAsset.Object);
	}

	//Determines if the actor has a status effect or not
	HasStatus = true;

	//The type of status to apply
	Status = "Ice";
	
}