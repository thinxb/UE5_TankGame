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

	//�������
	UPROPERTY(EditDefaultsOnly,Category = "Combat")
	float FireRange = 500.0f;


	//��ʱ��
	FTimerHandle FireRateTimerHandle;

	//����
	float FireRate = 2.0f;

	//�Ƿ񿪻�
	void CheckFireCondition();

	//�Ƿ��ڿ���Χ
	bool InFireRange();
};
