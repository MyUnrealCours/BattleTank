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
	
public:
	ATank* GetControlledTank() const;
	ATank* GetFirstPlayerTank() const;
	bool GetSightRayHitlocation(FVector &OUTHitLocation) const;
	
	
};
