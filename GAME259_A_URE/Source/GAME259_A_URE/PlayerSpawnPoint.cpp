// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSpawnPoint.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APlayerSpawnPoint::APlayerSpawnPoint()
{
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
    RootComponent = MeshComp;
    SetActorHiddenInGame(true);
}

// Called when the game starts or when spawned
void APlayerSpawnPoint::BeginPlay()
{
    Super::BeginPlay();

    MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

