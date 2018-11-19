// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "MyNavMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class BT_API UMyNavMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintCallable)
	void IntendMoveForward(float press);
	
};
