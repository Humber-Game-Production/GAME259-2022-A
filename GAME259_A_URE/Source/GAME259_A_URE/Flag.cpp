// Fill out your copyright notice in the Description page of Project Settings.


#include "Flag.h"

AFlag::AFlag()
{
	bReplicates = true;


}

void AFlag::BeginPlay()
{
	Super::BeginPlay();

}

void AFlag::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFlag, owningTeam);
}