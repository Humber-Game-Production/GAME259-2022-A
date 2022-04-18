// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GrenadeActor.generated.h"



UCLASS()
class GAME259_A_URE_API AGrenadeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrenadeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	//Set whether to enable debug options
	UPROPERTY(EditAnywhere, Category = "Debug")
		bool Debug;

	//Stores the amount of damage to deal
	UPROPERTY(EditAnywhere, Category = "Input")
		float DamageToDeal;

	//Stores the mesh component
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
		UStaticMeshComponent* SphereMesh;

	//Stores the material
	UPROPERTY(EditAnywhere, Category = "Material")
		UMaterial* SphereMaterial;

	//Stores the sphere component
	UPROPERTY(VisibleDefaultsOnly, Category = "Sphere")
		USphereComponent* SphereComp;

	//Stores the type of status
	UPROPERTY(EditAnywhere, Category = "Input")
		FName Status;
	
	UFUNCTION(BlueprintCallable)
		void ApplyImpulse(FVector impulse_);

	//Overlap function for destroying the actor and broadcasting delegates
	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
