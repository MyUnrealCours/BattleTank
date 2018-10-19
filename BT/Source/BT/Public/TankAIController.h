// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BT_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

public:
	ATank* GetControlledTank() const;
	ATank* GetFirstPlayerTank() const;
	
	
};
