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
	bool triggered; //ability is triggered

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Stores the sphere component
	UPROPERTY(VisibleDefaultsOnly, Category = "Collison")
		class USphereComponent* BallRepulsorCollision;

	UFUNCTION(BlueprintCallable)
		bool getTriggered() { return triggered; }
	UFUNCTION(BlueprintCallable)
		void setTriggered(bool triggered_) { triggered = triggered_; }

	UFUNCTION(BlueprintCallable)
		bool getSendRequest() { return sendRequest; }
	UFUNCTION(BlueprintCallable)
		void setSendRequest(bool sendRequest_) { sendRequest = sendRequest_; }


	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void EndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


};
