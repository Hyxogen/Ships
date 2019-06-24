// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Pawn/Components/ShipMovementComponent.h"

UShipMovementComponent::UShipMovementComponent() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UShipMovementComponent::BeginPlay() {
	Super::BeginPlay();
}

void UShipMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}