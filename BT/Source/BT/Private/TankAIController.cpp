// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* AITankName = GetControlledTank();
	if (AITankName)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing: %s "), *AITankName->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing nothing."))
	}
	
}

ATank * ATankAIController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}
