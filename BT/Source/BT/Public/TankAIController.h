// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class BT_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	float AcceptedRadius = 3000.0f;

protected:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000.0f;

	
};
