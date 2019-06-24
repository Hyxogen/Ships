// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ship.generated.h"

class UCameraComponent;
class UShipMovementComponent;

UCLASS()
class SHIPS_API AShip : public APawn {
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* m_StaticMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
		UCameraComponent* m_Camera;
public:
	AShip();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UShipMovementComponent* m_ShipMovement;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
