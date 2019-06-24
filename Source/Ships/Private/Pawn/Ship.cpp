// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Pawn/Ship.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "Public/Pawn/Components/ShipMovementComponent.h"

AShip::AShip() {
	PrimaryActorTick.bCanEverTick = true;

	m_StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = (USceneComponent*) m_StaticMesh;

	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	m_Camera->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	m_ShipMovement = CreateDefaultSubobject<UShipMovementComponent>(TEXT("Movement Controller"));
}

void AShip::BeginPlay() {
	Super::BeginPlay();

}

void AShip::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	m_ShipMovement->m_Input = PlayerInputComponent;
}