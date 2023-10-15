// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOOKTANKS_API ATower : public AMyPawn
{
	GENERATED_BODY()

public:

	ATower();

	virtual void Tick(float DeltaTime) override;
	
	void HandleDestruction();

protected:

	virtual void BeginPlay()override;


private:

	class ATank* Tank;

	//开火距离
	UPROPERTY(EditDefaultsOnly,Category = "Combat")
	float FireRange = 500.0f;

	//伤害组件
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UHealthComponent* HealthComponent;

	//定时器
	FTimerHandle FireRateTimerHandle;

	//射速
	float FireRate = 2.0f;

	//是否开火
	void CheckFireCondition();

	//是否在开火范围
	bool InFireRange();
};
