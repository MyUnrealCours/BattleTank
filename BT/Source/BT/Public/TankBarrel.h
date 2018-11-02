// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BT_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float RelativeSpeed);

private:

	UPROPERTY(EditAnywhere, category = Setup)
	float MaxDegreePerSecond = 20.0;

	UPROPERTY(EditAnywhere, category = Setup)
	float MaxElevationDegree = 40.0; // TODO Set 

	UPROPERTY(EditAnywhere, category = Setup)
	float MinElevationDegree = 0.0; // TODO Set
	
};
