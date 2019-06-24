// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Pawn/Components/ShipMovementComponent.h"
#include "Engine/Classes/Components/InputComponent.h"
#include "Core//Public/Misc/App.h" 
#include "Engine/Classes/GameFramework/Actor.h"

UShipMovementComponent::UShipMovementComponent() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UShipMovementComponent::BeginPlay() {
	Super::BeginPlay();
	m_Input->BindAxis("Forward_Backwards", this, &UShipMovementComponent::ForwardInput);
	m_Input->BindAxis("Left_Right", this, &UShipMovementComponent::RightInput);
	m_Actor = GetOwner();
}

void UShipMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	m_CurrentSpeed = GetSpeedScale();
	m_Actor->SetActorLocation(m_Actor->GetTargetLocation() + (m_Actor->GetActorForwardVector() * m_CurrentSpeed));
}

void UShipMovementComponent::ForwardInput(float scale) {
	float current = m_Throttle;
	current += scale * m_ThrottleSpeed * FApp::GetDeltaTime();

	if (current > m_MaxThrotle)
		current = m_MaxThrotle;
	else if (current < m_MinThrottle)
		current = m_MinThrottle;

	m_Throttle = current;
}

void UShipMovementComponent::RightInput(float scale) {
	float trueSpeed = GetSpeedScale();
	float deltaTime = FApp::GetDeltaTime();

	FRotator rotator(0.0f, m_TurnSpeed * scale * deltaTime * (trueSpeed/m_MaxSpeed), 0.0f);
	m_Actor->AddActorWorldRotation(rotator.Quaternion());
}

float UShipMovementComponent::GetSpeedScale() const {
	float deltaTime = FApp::GetDeltaTime();
	float designedSpeed = (m_Throttle / m_MaxThrotle) * m_MaxSpeed;
	float trueSpeed = m_CurrentSpeed;

	if (designedSpeed > trueSpeed) {
		if ((trueSpeed + m_Acceleration * deltaTime) > m_MaxSpeed) {
			trueSpeed = m_MaxSpeed;
		}
		else {
			trueSpeed += m_Acceleration * deltaTime;
		}
	}
	else if (designedSpeed < trueSpeed) {
		if ((trueSpeed + -m_Acceleration * deltaTime) < m_MinSpeed) {
			trueSpeed = m_MaxSpeed;
		}
		else {
			trueSpeed += -m_Acceleration * deltaTime;
		}
	}
	return trueSpeed;
}