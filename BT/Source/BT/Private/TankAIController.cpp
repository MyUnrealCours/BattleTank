// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* PlayerFound = GetFirstPlayerTank();
	if (PlayerFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found: %s "), *PlayerFound->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found nothing."))
	}
	
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetFirstPlayerTank() const
{
	ATank* PlayerZero = Cast<ATank>(GetWorld()-> GetFirstPlayerController()->GetPawn());
	if (PlayerZero == nullptr)
		return nullptr;
	else
		return PlayerZero;
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// UE_LOG(LogTemp, Warning, TEXT("Tick! Tick! Tick!"));
	auto PlayerTank = GetFirstPlayerTank();
	if (PlayerTank)
	{
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
	}
}
