// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* TankName = NULL;
	TankName = GetControlledTank();
	if (TankName)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possesing: %s"), *TankName->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possesing nothing."));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}




