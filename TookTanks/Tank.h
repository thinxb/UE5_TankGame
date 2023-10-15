// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOOKTANKS_API ATank : public AMyPawn
{
	GENERATED_BODY()

public:
	ATank();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	APlayerController* GetTankPlayerController()const { return TankPlayerController; };

	bool bAlive = true;

private:
	UPROPERTY(VisibleAnyWhere,Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere,Category = "Movement")
	float Speed = 200.0f;


	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 200.0f;




	//前后移动
	void Move(float Value);
	//左右旋转
	void Turn(float Value);
	
	APlayerController* TankPlayerController;


};
