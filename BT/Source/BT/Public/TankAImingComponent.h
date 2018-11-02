// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAImingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BT_API UTankAImingComponent : public UActorComponent
{
	GENERATED_BODY()

   UTankBarrel* Barrel = nullptr;
   UTankTurret* Turret = nullptr;
   void	MoveBarrel(FVector &AimDirection);

public:	
	// Sets default values for this component's properties
	UTankAImingComponent();

	void AimAt(FVector WorldSpaceAim, float LaunchSpeed);
	
	void SetBarrel(UTankBarrel* BarrelToSet);
	void SetTurret(UTankTurret* TurretToSet);
		
	
};
