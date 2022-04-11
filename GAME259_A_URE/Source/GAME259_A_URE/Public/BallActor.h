// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "Components/SphereComponent.h"
#include "BallActor.generated.h"


UENUM(BlueprintType)
enum EBallType {
	BallDefault, //0
	BallFire, //1
	BallIce //2
};

//DataTable Row
USTRUCT(BlueprintType)
struct FBallRow : public FTableRowBase {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName statusName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EBallType> ballType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float damageToDeal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMesh* ballMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterial* ballMaterial;

};

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
	FName Status;
	
	//Determines if the actor is lethal or not
	UPROPERTY(EditAnywhere, Category = "Input")
	bool IsLethal;

	//Determines if the actor has a status effect or not
	UPROPERTY(EditAnywhere, Category = "Input")
	bool HasStatus;

	UPROPERTY(EditAnywhere, Category = "Input")
	float lethalVelocity;

	UPROPERTY(EditAnywhere, Category = "Input")
	TEnumAsByte<EBallType> ballType;
	
	//Starting time for the destroying the object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	float DestroyTimer;

	//Set whether to enable debug options
	UPROPERTY(EditAnywhere, Category = "Debug")
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

	UFUNCTION(BlueprintCallable)
	void ApplyForce(float force_);

	UFUNCTION(BlueprintCallable)
	void ApplyImpulse (FVector impulse_);

	UFUNCTION(BlueprintCallable)
	void setValue(UStaticMesh* sphereMesh_, UMaterial* sphereMaterial_, 
			float damageToDeal_, FName combatStatus_, TEnumAsByte<EBallType> ballType_, bool isLethal_);

	//Function used by the timer to determine what happens when the destroy timer is up
	UFUNCTION()
	void DestroyTimerUp();

	//Overlap function for destroying the actor and broadcasting delegates
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,  bool bFromSweep, const FHitResult &SweepResult );
};


