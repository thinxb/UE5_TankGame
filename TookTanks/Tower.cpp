// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "HealthComponent.h"

ATower::ATower()
{
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//����Ƿ��������
	if (InFireRange())
	{
		//����ڷ�Χ�� ��������׼̹��
		RotatorTurret(Tank->GetActorLocation());

	}

}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ATower::BeginPlay()
{
	Super::BeginPlay();


	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle,this,&ATower::CheckFireCondition,FireRate,true);
}

void ATower::CheckFireCondition()
{
	if (Tank == nullptr)
	{
		return;
	}

	//����Ƿ��������
	if (InFireRange() && Tank->bAlive)
	{

		//����
		Fire();
		FVector ProjectileSpwanPointLocation = GetActorLocation();

		//FHitResult HitResult;
		//DrawDebugSphere(
		//	GetWorld(),
		//	ProjectileSpwanPointLocation,
		//	25.0f,
		//	12,
		//	FColor::Red,
		//	false,
		//	3.0f);
	}

}

bool ATower::InFireRange()
{
	if (Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		if (Distance <= FireRange)
		{
			return true;
		}
	}

	return false;
}
