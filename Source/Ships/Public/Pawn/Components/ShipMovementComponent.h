// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShipMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHIPS_API UShipMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UShipMovementComponent();

	UPROPERTY(VisibleAnywhere, Category = "Ship settings")
	float m_MaxSpeed = 100.0f;

	

protected:
	virtual void BeginPlay() override;

	void Init();

	UPROPERTY(VisibleAnywhere)
	float m_Throttle = 0.0f;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
};
