// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAImingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "TankTurret.h"




// Sets default values for this component's properties
UTankAImingComponent::UTankAImingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAImingComponent::AimAt(FVector WorldSpaceAim,float LaunchSpeed)
{
	
	if (!Barrel) { return;}

	FVector OutTossVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutTossVelocity,
		StartLocation,
		WorldSpaceAim,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutTossVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);

	}
}


void UTankAImingComponent::initialise(UTankBarrel * TankBarrel, UTankTurret * TankTurret)
{
	Turret = TankTurret;
	Barrel = TankBarrel;
}


void UTankAImingComponent::MoveBarrel(FVector &AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}


