// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOOKTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()
	

public:

	//演员的死亡
	void ActorDied(AActor* DeadActor);

protected:
	virtual void BeginPlay()override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame(); 

	//游戏是否结束
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);

private:

	//获取一个坦克指针
	class ATank* Tank;

	class AToonTanksPlayerController* ToonTanksPlayerController;

	float StartDelay = 3.0f;

	void HandleGameStart();

	//记录炮塔数量
	int32 TargetTowers = 0;

	//获取炮塔数量
	int32 GetTargerTowers();


};
