// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"

#include "Kismet/GamePlayStatics.h"
#include "ToonTanksPlayerController.h"
#include "Tank.h"
#include "Tower.h"
 
void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	//��ʼ����������
	TargetTowers = GetTargerTowers();

	//����������Ƿ���̹��
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
	//���ڻ�ȡ��Ϸ�еĵ�һ����ҿ��ƵĽ�ɫ�������ɫ����ת����һ��ATank���󣬲��洢�ڱ��� Tank �С�
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	//��ȡ��ҿ�������AToonTanksPlayerController��  ���ڻ�ȡ��Ϸ�еĵ�һ����ҿ��������������������ת����һ��AToonTanksPlayerController���󣬲��洢�ڱ��� ToonTanksPlayerController ��
	ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	StartGame();



	//����Ƿ�ɹ���ȡ����ҿ����� (ToonTanksPlayerController)
	if (ToonTanksPlayerController)
	{
		ToonTanksPlayerController->SetPlayerEnabledState(false);


		FTimerHandle PlayerEnableTimerHandle;

		//��ʱ�����������⽫���ӳ�ʱ������ 
		// ToonTanksPlayerController �� SetPlayerEnabledState ������
		// ������ true ��Ϊ������������������ҿ���
		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(
			ToonTanksPlayerController,
			&AToonTanksPlayerController::SetPlayerEnabledState,
			true
		);


		//�����ʱ������һ���ӳ�֮�󴥷���
		//StartDelay ����ȷ���˶�ʱ�����ӳ�ʱ�䡣
		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle,
			PlayerEnableTimerDelegate,
			StartDelay,
			false
		);
	}
}


int32 AToonTanksGameMode::GetTargerTowers()
{
	//�洢��������
	TArray<AActor*> Towers;

	//�洢����
	UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);

	return Towers.Num();
}
