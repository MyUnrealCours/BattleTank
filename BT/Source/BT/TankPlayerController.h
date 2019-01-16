// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = Setup)
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
	void FoundAimingComponent(UTankAImingComponent* AimingComponent);
private:
	
	ATank* GetFirstPlayerTank() const;
	bool GetSightRayHitlocation(FVector &OUTHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0;

	bool GetLookDirection(FVector2D &ScreenLocation, FVector &LookDirection) const;
	bool GetLookVectorHitLocation(FVector &OutHitLocation, FVector &LookDirection) const;
	
	
};
