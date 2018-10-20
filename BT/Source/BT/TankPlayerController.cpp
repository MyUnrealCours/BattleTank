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
	//Finding Crosshair position in pixel coordinates.
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	
	//Derojection the crosshair position to world.
	FVector  CameraDirection;
	if (GetLookDirection(ScreenLocation,CameraDirection))
	{
		GetLookVectorHitLocation(OUTHitLocation, CameraDirection);
	}
	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D & ScreenLocation, FVector & LookDirection) const
{
	FVector CameraLocation;// to be deleted  
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraLocation, 
		LookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector &OutHitLocation,FVector & LookDirection) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	else
		return false;
}




