// Fill out your copyright notice in the Description page of Project Settings.


#include "GAME259_Flag.h"

AGAME259_Flag::AGAME259_Flag()
{
	bReplicates = true;


}

void AGAME259_Flag::BeginPlay()
{
	Super::BeginPlay();

}

void AGAME259_Flag::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGAME259_Flag, owningTeam);
}