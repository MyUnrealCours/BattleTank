// Fill out your copyright notice in the Description page of Project Settings.

#include "MyNavMovementComponent.h"
#include "TankTrack.h"

void UMyNavMovementComponent::IntendMoveForward(float press)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(press);
	RightTrack->SetThrottle(press);
}

void UMyNavMovementComponent::IntendRight(float press)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(press);
	RightTrack->SetThrottle(-press);
}

void UMyNavMovementComponent::initialise(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{


	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}
