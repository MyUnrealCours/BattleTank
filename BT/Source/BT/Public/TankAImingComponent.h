// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAImingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BT_API UTankAImingComponent : public UActorComponent
{
	GENERATED_BODY()

		UStaticMeshComponent* Barrel = nullptr;

public:	
	// Sets default values for this component's properties
	UTankAImingComponent();

	void AimAt(FVector WorldSpaceAim);
	
	void SetBarrel(UStaticMeshComponent* BarrelToSet);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
