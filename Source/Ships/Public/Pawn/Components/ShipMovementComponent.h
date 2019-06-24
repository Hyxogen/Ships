// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShipMovementComponent.generated.h"

class UInputComponent;
class USphereComponent;
class AActor;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHIPS_API UShipMovementComponent : public UActorComponent {
	GENERATED_BODY()

public:
	UShipMovementComponent();

	UPROPERTY(EditAnywhere)
	float m_MaxSpeed = 100.0f;

	UPROPERTY(EditAnywhere)
	float m_MinSpeed = -5.0f;

	UPROPERTY(EditAnywhere)
	float m_Acceleration = 2.0f;

	UPROPERTY(EditAnywhere)
	float m_TurnSpeed = 1.0f;

	UInputComponent* m_Input;

protected:
	virtual void BeginPlay() override;

	float m_Throttle = 0.0f;
	float m_MaxThrotle = 5.0f;
	float m_MinThrottle = -1.5f;
	float m_ThrottleSpeed = 1.0f;

	float m_CurrentSpeed = 0.0f;

	AActor* m_Actor;

	void ForwardInput(float scale);
	void RightInput(float scale);

	float GetSpeedScale() const;
public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
