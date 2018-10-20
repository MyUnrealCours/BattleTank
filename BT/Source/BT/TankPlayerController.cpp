// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* TankName = GetFirstPlayerTank();
	if (TankName)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possesing: %s"), *TankName->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possesing nothing."));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector HitLocation;
	if (GetSightRayHitlocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location : %s"), *HitLocation.ToString());
	}
	
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankPlayerController::GetFirstPlayerTank() const
{
	ATank* PlayerZero = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerZero == nullptr)
		return nullptr;
	else
		return PlayerZero;
}

bool ATankPlayerController::GetSightRayHitlocation(FVector & OUTHitLocation) const
{
	OUTHitLocation = FVector(1.0);
	return true;
}




