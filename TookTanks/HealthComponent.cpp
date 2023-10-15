// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "ToonTanksGameMode.h"
#include "Kismet/GamePlayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;


	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaKen);
	
	ToonTanksGameMode = Cast<AToonTanksGameMode>(UGameplayStatics::GetGameMode(this));

	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UHealthComponent::DamageTaKen(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser)
{
	//如果生命值小于等于0 直接返回
	if (Damage <= 0.0f) return;
	Health -= Damage;
	//UE_LOG(LogTemp, Warning, TEXT("Health: %f"), Health);

	if (Health <= 0.0f && ToonTanksGameMode)
	{
		//UE_LOG(LogTemp, Warning, TEXT("ActorDied"));
		ToonTanksGameMode->ActorDied(DamageActor);
	}


	
}
