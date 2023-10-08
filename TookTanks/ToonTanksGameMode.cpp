// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"

#include "Kismet/GamePlayStatics.h"
#include "ToonTanksPlayerController.h"
#include "Tank.h"
#include "Tower.h"
 
void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	//����������Ƿ���̹��
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if (ToonTanksPlayerController)
		{
			ToonTanksPlayerController->SetPlayerEnabledState(false);
		}
	}
	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
	}

}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();

}

void AToonTanksGameMode::HandleGameStart()
{
	//���ڻ�ȡ��Ϸ�еĵ�һ����ҿ��ƵĽ�ɫ�������ɫ����ת����һ��ATank���󣬲��洢�ڱ��� Tank �С�
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	//��ȡ��ҿ�������AToonTanksPlayerController��  ���ڻ�ȡ��Ϸ�еĵ�һ����ҿ��������������������ת����һ��AToonTanksPlayerController���󣬲��洢�ڱ��� ToonTanksPlayerController ��
	ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

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