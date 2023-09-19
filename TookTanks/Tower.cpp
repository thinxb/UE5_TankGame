// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"

ATower::ATower()
{
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//检查是否在射程内
	if (InFireRange())
	{
		//如果在范围内 将炮塔对准坦克
		RotatorTurret(Tank->GetActorLocation());

	}

}

void ATower::BeginPlay()
{
	Super::BeginPlay();


	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle,this,&ATower::CheckFireCondition,FireRate,true);
}

void ATower::CheckFireCondition()
{

	//检查是否在射程内
	if (InFireRange())
	{

		//开火
		Fire();
		FVector ProjectileSpwanPointLocation = GetActorLocation();

		FHitResult HitResult;
		DrawDebugSphere(
			GetWorld(),
			ProjectileSpwanPointLocation,
			25.0f,
			12,
			FColor::Red,
			false,
			3.0f);
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
