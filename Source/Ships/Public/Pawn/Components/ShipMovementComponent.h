// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShipMovementComponent.generated.h"

class UInputComponent;
class USphereComponent;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHIPS_API UShipMovementComponent : public UActorComponent {
	GENERATED_BODY()

public:
	UShipMovementComponent();

	float m_MaxSpeed = 100.0f;

	UInputComponent* m_Input;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		float m_Throttle = 0.0f;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
