// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAME259_PlayerSpawnPoint.generated.h"

UCLASS()
class GAME259_A_URE_API AGAME259_PlayerSpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGAME259_PlayerSpawnPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Mesh")
		class UStaticMeshComponent* MeshComp;

};
