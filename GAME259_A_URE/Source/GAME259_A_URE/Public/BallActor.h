// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "BallActor.generated.h"

//Dynamic one parameter delegate used for broadcasting the amount of time to deal
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageDamage, float, FDamage);

//Dynamic one parameter delegate used for broadcasting the type of status
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageStatus, FString, FStatus);

UCLASS()
class GAME259_A_URE_API ABallActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Stores the amount of damage to deal
	UPROPERTY(EditAnywhere, Category = "Input")
	float DamageToDeal;

	//Stores the type of status
	UPROPERTY(EditAnywhere, Category = "Input")
	FString Status;
	
	//Determines if the actor is lethal or not
	UPROPERTY(EditAnywhere, Category = "Input")
	bool IsLethal;

	//Determines if the actor has a status effect or not
	UPROPERTY(EditAnywhere, Category = "Input")
	bool HasStatus;

	UPROPERTY(EditAnywhere, Category = "Input")
	float lethalVelocity;
	
	//Starting time for the destroying the object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	float DestroyTimer;

	//Set whether to enable debug options
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	bool Debug;
	
	//The timer handler for the game's time
	UPROPERTY(EditAnywhere, Category = "Timer")
	FTimerHandle TimeHandle;;
	
	//Stores the mesh component
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* SphereMesh;

	//Stores the material
	UPROPERTY(EditAnywhere, Category = "Material")
	UMaterial* SphereMaterial;

	//Stores the sphere component
	UPROPERTY(VisibleDefaultsOnly, Category = "Sphere")
	USphereComponent* SphereComp;

	//Dispatcher for the amount of damage to deal
	UPROPERTY(BlueprintAssignable, Category = "Dispatcher")
	FMessageDamage MessageDamage;

	//Dispatcher for the amount of damage to deal
	UPROPERTY(BlueprintAssignable, Category = "Dispatcher")
	FMessageStatus MessageStatus;


	//Function used by the timer to determine what happens when the destroy timer is up
	UFUNCTION()
	void DestroyTimerUp();

	//Overlap function for destroying the actor and broadcasting delegates
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,  bool bFromSweep, const FHitResult &SweepResult );
};