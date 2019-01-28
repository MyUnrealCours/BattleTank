// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAImingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Locked,
	Aiming,
	Reloading
};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BT_API UTankAImingComponent : public UActorComponent
{
	GENERATED_BODY()

		

   void	MoveBarrel(FVector &AimDirection);

   UPROPERTY(EditDefaultsOnly, Category = "Firing")
   float LaunchSpeed = 4000;


   UPROPERTY(EditDefaultsOnly, Category = Firing)
   float ReloadTimeInSeconds = 3.0f;

  

   UPROPERTY(EditAnywhere, category = Setup)
   TSubclassOf<AProjectile> ProjectileBluePrint;

    double LastFireTime = 0;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

public:	
	// Sets default values for this component's properties
	UTankAImingComponent();

	void AimAt(FVector WorldSpaceAim);

	UFUNCTION(BlueprintCallable)
	void initialise(UTankBarrel* TankBarrel, UTankTurret* TankTurret);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();
protected:
	UPROPERTY(BlueprintReadOnly, Category = State)
	EFiringState FiringState = EFiringState::Reloading;
		
	
};
