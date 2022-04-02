// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CTF_GameMode.h"
#include "GameFramework/Actor.h"
#include "PlayerSpawnPoint.generated.h"


UCLASS()
class GAME259_A_URE_API APlayerSpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerSpawnPoint();

	UPROPERTY(EditAnywhere)
	TeamSelected owningTeam;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Mesh")
		class UStaticMeshComponent* MeshComp;

};
