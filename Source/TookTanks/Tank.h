// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOOKTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	UPROPERTY(VisibleAnyWhere,Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	class UCameraComponent* Camera;


	void Move(float Value);

	


};
