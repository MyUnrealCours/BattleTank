// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAImingComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;
class UMyNavMovementComponent;

UCLASS()
class BT_API ATank : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 1000.0f;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3.0f;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	double LastFireTime = 0;



public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector HitLocation);

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAImingComponent* TankAimingComponent = nullptr;

	UPROPERTY(EditAnywhere, category = Setup)
	TSubclassOf<AProjectile> ProjectileBluePrint;

	UPROPERTY(BlueprintReadOnly)
	UMyNavMovementComponent* MovementComponent = nullptr;


	UTankBarrel* Barrel;	
	
};
