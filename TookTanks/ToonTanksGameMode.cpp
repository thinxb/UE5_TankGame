// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"

#include "Kismet/GamePlayStatics.h"
#include "ToonTanksPlayerController.h"
#include "Tank.h"
#include "Tower.h"
 
void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	//初始化炮塔数量
	TargetTowers = GetTargerTowers();

	//检查死亡的是否是坦克
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if (ToonTanksPlayerController)
		{
			ToonTanksPlayerController->SetPlayerEnabledState(false);
		}
		GameOver(false);
	}
	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
		TargetTowers--;
		if (TargetTowers == 0)
		{
			GameOver(true);
		}
	}

}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();

}

//void AToonTanksGameMode::GameOver(bool bWonGame)
//{
//	UE_LOG(LogTemp, Warning, TEXT("Over"));
//}

//void AToonTanksGameMode::StartGame()
//{
//
//}

void AToonTanksGameMode::HandleGameStart()
{
	//用于获取游戏中的第一个玩家控制的角色。这个角色将被转换成一个ATank对象，并存储在变量 Tank 中。
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	//获取玩家控制器（AToonTanksPlayerController）  用于获取游戏中的第一个玩家控制器。这个控制器将被转换成一个AToonTanksPlayerController对象，并存储在变量 ToonTanksPlayerController 中
	ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	StartGame();



	//检查是否成功获取了玩家控制器 (ToonTanksPlayerController)
	if (ToonTanksPlayerController)
	{
		ToonTanksPlayerController->SetPlayerEnabledState(false);


		FTimerHandle PlayerEnableTimerHandle;

		//定时器被启动，这将在延迟时间后调用 
		// ToonTanksPlayerController 的 SetPlayerEnabledState 方法，
		// 并传入 true 作为参数，以重新启用玩家控制
		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(
			ToonTanksPlayerController,
			&AToonTanksPlayerController::SetPlayerEnabledState,
			true
		);


		//这个定时器会在一定延迟之后触发。
		//StartDelay 变量确定了定时器的延迟时间。
		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle,
			PlayerEnableTimerDelegate,
			StartDelay,
			false
		);
	}
}


int32 AToonTanksGameMode::GetTargerTowers()
{
	//存储炮塔数组
	TArray<AActor*> Towers;

	//存储炮塔
	UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);

	return Towers.Num();
}
