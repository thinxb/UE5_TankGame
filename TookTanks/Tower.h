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

	//�������
	UPROPERTY(EditDefaultsOnly,Category = "Combat")
	float FireRange = 500.0f;

	//�˺����
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UHealthComponent* HealthComponent;

	//��ʱ��
	FTimerHandle FireRateTimerHandle;

	//����
	float FireRate = 2.0f;

	//�Ƿ񿪻�
	void CheckFireCondition();

	//�Ƿ��ڿ���Χ
	bool InFireRange();
};
