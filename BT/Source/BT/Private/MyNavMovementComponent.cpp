// Fill out your copyright notice in the Description page of Project Settings.

#include "MyNavMovementComponent.h"
#include "TankTrack.h"

void UMyNavMovementComponent::IntendMoveForward(float press)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward: %f"), press);
	LeftTrack->SetThrottle(press);
	RightTrack->SetThrottle(press);
}

void UMyNavMovementComponent::initialise(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}
