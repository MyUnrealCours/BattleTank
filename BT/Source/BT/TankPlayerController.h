// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

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
	
private:
	ATank* GetControlledTank() const;
	ATank* GetFirstPlayerTank() const;
	bool GetSightRayHitlocation(FVector &OUTHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

	bool GetLookDirection(FVector2D &ScreenLocation, FVector &LookDirection) const;
	
	
};
