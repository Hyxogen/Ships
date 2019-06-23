// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Pawn/Ship.h"
#include "Engine/Classes/Camera/CameraComponent.h"

AShip::AShip() {
	PrimaryActorTick.bCanEverTick = true;

	m_StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = m_StaticMesh;

	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	m_Camera->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AShip::BeginPlay() {
	Super::BeginPlay();

}

void AShip::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

