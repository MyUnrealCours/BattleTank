// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Public/TankAImingComponent.h"
#include "Engine/World.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAImingComponent>();
	if (AimingComponent)
	{
		FoundAimingComponent(AimingComponent);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank aiming component not found in player controller."));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
	
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
		return GetLookVectorHitLocation(OUTHitLocation, CameraDirection);
	}
	
	return false;
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

void ATankPlayerController::AimTowardsCrosshair()
{

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAImingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitlocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		AimingComponent->AimAt(HitLocation);
	}
}



