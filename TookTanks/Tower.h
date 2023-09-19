// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOOKTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:

	ATower();

	virtual void Tick(float DeltaTime) override;
	
protected:

	virtual void BeginPlay()override;


private:

	class ATank* Tank;

	//开火距离
	UPROPERTY(EditDefaultsOnly,Category = "Combat")
	float FireRange = 500.0f;


	//定时器
	FTimerHandle FireRateTimerHandle;

	//射速
	float FireRate = 2.0f;

	//是否开火
	void CheckFireCondition();

	//是否在开火范围
	bool InFireRange();
};
