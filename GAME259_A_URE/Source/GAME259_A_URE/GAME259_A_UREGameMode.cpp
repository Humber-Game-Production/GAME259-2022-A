// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAME259_A_UREGameMode.h"
#include "GAME259_A_URECharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAME259_A_UREGameMode::AGAME259_A_UREGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
