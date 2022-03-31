// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Main_Character.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterHealthUpdate);

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterHPUpdate, float, characterHealth);

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

	//virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

protected:

	class UPlayerStatsComponent* PlayerStatsComp;

	virtual void FellOutOfWorld(const UDamageType& dmgType) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCombatStatusComponent* CombatStatusComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCombatAmmoContainerComponent* CombatAmmoContainerComp0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCombatAmmoContainerComponent* CombatAmmoContainerComp1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCombatAmmoContainerComponent* CombatAmmoContainerComp2;
	
	void Attack();

	//for testing
	void ManualAddBall();
	void ManualMinusBall();
	
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttack();
	bool ServerAttack_Validate();
	void ServerAttack_Implementation();

	void Die();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
		void MultiDie();
	bool MultiDie_Validate();
	void MultiDie_Implementation();

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

	/** The player's maximum health. This is the highest that their health can be, and the value that their health starts at when spawned.*/
	UPROPERTY(EditDefaultsOnly, Category = "Health")
		float MaxHealth;

	/** The player's current health. When reduced to 0, they are considered dead.*/
	UPROPERTY(EditDefaultsOnly, ReplicatedUsing = OnRep_CurrentHealth)
		float CurrentHealth;

	/** Update Health */
	void OnHealthUpdate();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	virtual void BeginPlay() override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
		FCharacterHealthUpdate HealthUpdate;

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
		void SetCurrentHealth(float healthValue);

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

	//Add Combat Status
	UFUNCTION(BlueprintCallable, Category = "CombatStatus")
		void AddCombatStatus(FName statusName_);
};