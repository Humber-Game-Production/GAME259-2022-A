#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStats.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GAME259_A_URE_API UPlayerStatsComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UPlayerStatsComponent();
protected:

    //UPROPERTY(Replicated)
    //float Hunger;

    //UPROPERTY(EditAnywhere, Category = "PlayerStats")
    //float HungerDecrementValue;

 //   UPROPERTY(Replicated)
    //float Thirst;

    //UPROPERTY(EditAnywhere, Category = "PlayerStats")
    //float ThirstDecrementValue;
    //
    //UPROPERTY(Replicated)
    //float Stamina;

    UPROPERTY(Replicated)
        float Health;

    //FTimerHandle TimerHandle;

    /*FTimerHandle StaminaHandle;*/

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

    //void HandleHungerAndThirst();

    //UFUNCTION(Server, Reliable, WithValidation)
    //    void ServerLowerHunger(float value);
    //bool ServerLowerHunger_Validate(float value);
    //void ServerLowerHunger_Implementation(float value);

    //UFUNCTION(Server, Reliable, WithValidation)
    //    void ServerLowerThirst(float value);
    //bool ServerLowerThirst_Validate(float value);
    //void ServerLowerThirst_Implementation(float value);

    //UFUNCTION(Server, Reliable, WithValidation)
    //    void ServerLowerStamina(float value);
    //bool ServerLowerStamina_Validate(float value);
    //void ServerLowerStamina_Implementation(float value);

    UFUNCTION(Server, Reliable, WithValidation)
        void ServerLowerHealth(float value);
    bool ServerLowerHealth_Validate(float value);
    void ServerLowerHealth_Implementation(float value);


    //void RegenerateStamina();
public:
    //void LowerHunger(float value);
    //void LowerThirst(float value);
    //void LowerStamina(float value);
    void LowerHealth(float value);
    //float GetThirst();
    //float GetHunger();
    //float GetStamina();
    float GetHealth();
    /*void ControlSprintingTimer(bool IsSprinting);*/
};
