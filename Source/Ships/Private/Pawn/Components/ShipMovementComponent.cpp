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
	m_Actor = GetOwner();
}

void UShipMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	m_CurrentSpeed = (m_Throttle / m_MaxThrotle) * m_MaxSpeed;
	FString str = FString::SanitizeFloat(m_CurrentSpeed);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *(m_Actor->GetActorForwardVector() * m_CurrentSpeed).ToString());
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