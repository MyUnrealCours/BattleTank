// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAImingComponent.h"


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

	UE_LOG(LogTemp, Warning, TEXT("Firing at launch speed : %f"), LaunchSpeed);
}

void UTankAImingComponent::SetBarrel(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAImingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAImingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

