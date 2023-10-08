// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksPlayerController.h"

#include "GameFramework/Pawn.h"

void AToonTanksPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
	if (bPlayerEnabled)
	{
		//启用与当前控制器相关联的角色（Pawn）的输入，以便玩家可以控制角色。
		GetPawn()->EnableInput(this);
	}
	else
	{
		//禁用与当前控制器相关联的角色的输入，防止玩家控制角色。
		GetPawn()->DisableInput(this);
	}

	//如果玩家被启用，光标将可见，否则将隐藏
	bShowMouseCursor = bPlayerEnabled;
}
