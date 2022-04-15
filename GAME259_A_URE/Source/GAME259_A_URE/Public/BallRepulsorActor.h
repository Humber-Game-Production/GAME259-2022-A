// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallRepulsorActor.generated.h"

UCLASS()
class GAME259_A_URE_API ABallRepulsorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallRepulsorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool sendRequest;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Stores the sphere component
	UPROPERTY(VisibleDefaultsOnly, Category = "Collison")
		class USphereComponent* BallRepulsorCollision;

	//Stores the sphere component
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		class UStaticMeshComponent* BallRepulsorMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = "Timer")
		FTimerHandle TimeHandle;

	UPROPERTY(EditAnywhere, Category = "Timer")
		float durationTime;

	UPROPERTY(VisibleDefaultsOnly, Category = "BallRepuslse")
		FVector rotationOffset;

	UFUNCTION(BlueprintCallable)
		void Activate();

	UFUNCTION(BlueprintCallable)
		float getDuration() { return durationTime; }
	UFUNCTION(BlueprintCallable)
		void setDuration(bool durationTime_) { durationTime = durationTime_; }

	UFUNCTION(BlueprintCallable)
		bool getSendRequest() { return sendRequest; }
	UFUNCTION(BlueprintCallable)
		void setSendRequest(bool sendRequest_) { sendRequest = sendRequest_; }

	UFUNCTION(BlueprintCallable)
		void OnDestroy();

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
