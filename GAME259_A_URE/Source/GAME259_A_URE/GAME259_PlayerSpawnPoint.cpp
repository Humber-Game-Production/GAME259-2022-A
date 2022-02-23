// Fill out your copyright notice in the Description page of Project Settings.


#include "GAME259_PlayerSpawnPoint.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AGAME259_PlayerSpawnPoint::AGAME259_PlayerSpawnPoint()
{
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
    RootComponent = MeshComp;
    SetActorHiddenInGame(true);
}

// Called when the game starts or when spawned
void AGAME259_PlayerSpawnPoint::BeginPlay()
{
    Super::BeginPlay();

    MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

