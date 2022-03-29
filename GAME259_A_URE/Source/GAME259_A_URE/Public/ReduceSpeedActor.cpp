#include "ReduceSpeedActor.h"
#include "CombatStatusComponent.h"
#include "Main_Character.h"

void AReduceSpeedActor::ApplyEffect(  )
{ 
	while (durationTime_ > 0.0f) 
	{
		
		setVelocity();
		durationTime_ - 0.5f;
		if (durationTime = 0.0f)
			//reset vel back to default
			break
	}
}
