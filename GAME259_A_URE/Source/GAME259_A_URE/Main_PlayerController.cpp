// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_PlayerController.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"

AMain_PlayerController::AMain_PlayerController() {
	StartSound = CreateDefaultSubobject<USoundBase>(TEXT("StartAudio"));
}

void AMain_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	//GEngine->AddOnScreenDebugMessage(-1, 120.0f, FColor::Red, GetName());
}

void AMain_PlayerController::PlaySound_Client_Implementation() {
	UGameplayStatics::PlaySound2D(GetWorld(), StartSound);
}
