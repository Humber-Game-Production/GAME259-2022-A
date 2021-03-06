// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/DataTable.h"
#include "Public/BallActor.h"
#include "Main_PlayerController.h"
#include "Main_Character.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterHealthUpdate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAmmoUpdate, int, index, int, ballNum);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPowerUpdate, int, powerLevel);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FKillerUpdate, FString, killerName);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAbilityCooldownUpdate, int, index, float, cd_percentage);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelayAttackUpdate);

//Setup current weapon delegate with index
class USoundBase;
class UAnimationMontage;

UCLASS(config = Game)
class AMain_Character : public ACharacter
{
	GENERATED_BODY()

		/** Camera boom positioning the camera behind the character */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

public:
	AMain_Character();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

protected:

	virtual void FellOutOfWorld(const UDamageType& dmgType) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCombatStatusComponent* CombatStatusComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCombatAmmoContainerComponent* CombatAmmoContainerComp0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCombatAmmoContainerComponent* CombatAmmoContainerComp1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCombatAmmoContainerComponent* CombatAmmoContainerComp2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStrafeComponent* StrafeAbility;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBallRepulsorComponent* BallRepulsorAbility;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UAudioComponent* FireAudio;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		class USoundBase* WalkingSound;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		class USoundBase* TakeDamageSound;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		class USoundBase* ShootingSound;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		class USoundBase* DeadSound;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		class USoundBase* PickupSound;

	void Attack();

	//for testing
	void ManualAddBall();
	void ManualMinusBall();

	void Die();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
		void MultiDie();
	bool MultiDie_Validate();
	void MultiDie_Implementation();

	//Combat abilities function
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void ActivateBallRepulsor_Server();

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
	void ActivateBallRepulsor_Multicast();

	
	UFUNCTION(BlueprintCallable)
		void ActivateStrafe();

	FTimerHandle DestroyHandle;

	void CallDestroy();

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	/** The player's maximum health. This is the highest that their health can be, and the value that their health starts at when spawned.*/
	UPROPERTY(EditDefaultsOnly, Category = "Health")
		float MaxHealth;

	/** The player's current health. When reduced to 0, they are considered dead.*/
	UPROPERTY(EditDefaultsOnly, ReplicatedUsing = OnRep_CurrentHealth)
		float CurrentHealth;

	/** Update Health */
	//void OnHealthUpdate(AController* EventInstigator, AActor* DamageCauser);

	void OnHealthUpdate();
	/*Setup for velocity
	  This is a percentage that effects velocity. 
	  Ex. When it is 1.0f, it means that the velocity is at 100% usage.
	  Ex. When it is 0.3f, it means that the crrunt velocity is only 30% of normal velocity*/
	UPROPERTY(EditDefaultsOnly, Category = "Player Stats")
		float velPercentage;

	UPROPERTY(EditAnywhere, Category = "Current Weapon")
		TEnumAsByte<EBallType> currentBall;

	UPROPERTY(EditAnywhere, Category = "Ball Spawn")
		float ballSpawnOffset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* ballSpawnLocation;

	UPROPERTY(EditDefaultsOnly, Category = "Ball Spawn")
		float impulse;

	UPROPERTY(EditDefaultsOnly, Category = "Ball Spawn")
		float impulseDef;

	UPROPERTY(EditDefaultsOnly, Category = "Ball Spawn")
		float impulseFire;
	
	UPROPERTY(EditDefaultsOnly, Category = "Ball Spawn")
		float impulseIce;
	
	
	UPROPERTY(EditDefaultsOnly, Category = "Ball Spawn")
		float impulseDefOrig;

	UPROPERTY(EditDefaultsOnly, Category = "Ball Spawn")
		float impulseFireOrig;

	UPROPERTY(EditDefaultsOnly, Category = "Ball Spawn")
		float impulseIceOrig;

	
	UPROPERTY(EditDefaultsOnly, Category = "Ball Spawn")
		float attackDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Ball Spawn")
		bool delayAttack;

	UPROPERTY(EditDefaultsOnly, Category = "Debug")
		bool debug;
	
	//The timer handler for the delay timer
	UPROPERTY(EditDefaultsOnly, Category = "Ball Spawn")
		FTimerHandle DelayHandle;;
	
public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UPROPERTY(EditAnywhere, Category = "Animation")
		class UAnimMontage* throwAnim;

	UPROPERTY(EditAnywhere, Category = "Data Table", Replicated)
		UDataTable* BallTable;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
		FCharacterHealthUpdate HealthUpdate;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
		FAmmoUpdate AmmoUpdate;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
		FAbilityCooldownUpdate AbilityCooldownUpdate;

	//Collection of ball slots
	UPROPERTY(EditAnywhere, Category = "Input")
	TArray<UCombatAmmoContainerComponent*> AmmoBallSlot;
	
	/** Getter for Max Health.*/
	UFUNCTION(BlueprintPure, Category = "Health")
		FORCEINLINE float GetMaxHealth() const { return MaxHealth; }

	/** Getter for Current Health.*/
	UFUNCTION(BlueprintPure, Category = "Health")
		FORCEINLINE float GetCurrentHealth() const { return CurrentHealth; }

	UFUNCTION()
		void OnRep_CurrentHealth();

	/** Setter for Current Health. Clamps the value between 0 and MaxHealth and calls OnHealthUpdate. Should only be called on the server.*/
	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetCurrentHealth(float healthValue, AController* EventInstigator, AActor* DamageCauser);

	// Event that will be triggered in the blueprint when player dies
	UFUNCTION(BlueprintImplementableEvent)
		void DeathEvent();

	/** Event for taking damage. Overridden from APawn.
	*   DamageEvent describes the type of damage.
	*	EventInstigator describes the controller that is responsible for the damage event.
	*	DamageCauser describes the Actor that deals damage.
	*/
	UFUNCTION(BlueprintCallable, Category = "Health")
		float TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	//Enables whether  to lower the power of impulse
	UPROPERTY(EditAnywhere, Category = "Debug")
		bool lowerPower;

	//Enables whether  to lower the power of impulse
	UPROPERTY(EditAnywhere, Category = "Debug")
		bool powerOn;
	
	//Add Combat Status
	UFUNCTION(BlueprintCallable, Category = "CombatStatus")
		void AddCombatStatus(FName statusName_, AController* EventInstigator);

	//Add Ball Ammo
	UFUNCTION(BlueprintCallable, Category = "Ammo")
		void AddBallAmmo(TEnumAsByte<enum EBallType> ballType, int ballNum);

	//Set velocity
	UFUNCTION(BlueprintCallable, Category = "Player Stats")
		void setVelocity(float velPrecentage_) { velPercentage = velPrecentage_; }

	//Reset velocity to 100%
	UFUNCTION(BlueprintCallable, Category = "Player Stats")
		void resetVelocity() { velPercentage = 1.0f; }

	UFUNCTION(BlueprintCallable)
		UCombatAmmoContainerComponent* GetAmmoContainer(TEnumAsByte<EBallType> ballType_);

	UFUNCTION(BlueprintCallable)
		void SetCurrentBall(TEnumAsByte<EBallType> newBall_) { currentBall = newBall_; }

	UFUNCTION(BlueprintCallable)
		void SetToBallType0(); 

	UFUNCTION(BlueprintCallable)
		void SetToBallType1();

	UFUNCTION(BlueprintCallable)
		void SetToBallType2();

	UFUNCTION(BlueprintCallable)
		void BallIndexIncrease();

	UFUNCTION(BlueprintCallable)
		void BallIndexDecrease();


	UFUNCTION(BlueprintCallable)
		FString GetNameOfActor();

	UFUNCTION(BlueprintCallable)
		UDataTable* GetBallDataTable() {
		return BallTable;
	}

	//Function used to spawn the ball in front of the player
	UFUNCTION(BlueprintCallable, Server, Reliable)
		void SpawnBallBP_Server(FVector location, FRotator rotation, FVector impulse_, TSubclassOf<class ABallActor> ballActorClass_);

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
		void SpawnBallBP_NetMulticast(FVector location, FRotator rotation, FVector impulse_, TSubclassOf<class ABallActor> ballActorClass_);

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
		void PlaySound_Multicast(USoundBase* sound_, FVector location_);

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void PlaySound_Server(USoundBase* sound_, FVector location_);

	//Function to set whether to lower the impulse
	UFUNCTION(BlueprintCallable)
		void LowPower();

	//Function to set whether to use maximum impulse
	UFUNCTION(BlueprintCallable)
		void FullPower();

	//Function used to set the attack delay
	UFUNCTION(BlueprintCallable)
		void DelayAttack();
	
	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
		FDelayAttackUpdate DelayAttackUpdate;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
		FPowerUpdate PowerUpdate;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
		FKillerUpdate KillerUpdate;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ABallActor> BallDefaultClass;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ABallActor> BallIceClass;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ABallActor> BallFireClass;

	UFUNCTION(BlueprintCallable)
		void On_Destroy();

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
	void PlayAnimation_Multicast(UAnimMontage* throwAnim_);

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void PlayAnimation_Server(UAnimMontage* throwAnim_);
};

USTRUCT()
struct FOvertimeDamageEvent : public FDamageEvent
{
	GENERATED_BODY()

};