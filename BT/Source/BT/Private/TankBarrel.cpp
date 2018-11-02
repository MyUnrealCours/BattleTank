// Fill out your copyright notice in the Description page of Project Settings.
#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto ElevationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->GetDeltaSeconds();
	auto RawElevation = RelativeRotation.Pitch + ElevationChange;
	FMath::Clamp<float>(RawElevation, MinElevationDegree, MaxElevationDegree);
	SetRelativeRotation(FRotator(RawElevation, 0.0, 0.0));
}


