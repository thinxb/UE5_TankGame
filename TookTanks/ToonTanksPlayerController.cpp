// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksPlayerController.h"

#include "GameFramework/Pawn.h"

void AToonTanksPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
	if (bPlayerEnabled)
	{
		//�����뵱ǰ������������Ľ�ɫ��Pawn�������룬�Ա���ҿ��Կ��ƽ�ɫ��
		GetPawn()->EnableInput(this);
	}
	else
	{
		//�����뵱ǰ������������Ľ�ɫ�����룬��ֹ��ҿ��ƽ�ɫ��
		GetPawn()->DisableInput(this);
	}

	//�����ұ����ã���꽫�ɼ�����������
	bShowMouseCursor = bPlayerEnabled;
}
