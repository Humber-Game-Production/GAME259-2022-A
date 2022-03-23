// Fill out your copyright notice in the Description page of Project Settings.


#include "ReduceSpeedActor.h"

AReduceSpeedActor::AReduceSpeedActor(){}


void AReduceSpeedActor::ApplyEffect() {
	Super::ApplyEffect();
	UE_LOG(LogTemp, Warning, TEXT("This is a ReduceSpeed actor."));
	//Implement code here

}