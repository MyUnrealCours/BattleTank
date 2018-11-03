// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAImingComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BT_API ATank : public APawn
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000.0f;


public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrel(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurret(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAImingComponent* TankAimingComponent = nullptr;

	UPROPERTY(EditAnywhere, category = Setup)
	TSubclassOf<AProjectile> ProjectileBluePrint;

	UTankBarrel* Barrel;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
