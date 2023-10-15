// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

#include "Projectile.h"
#include "Engine/World.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpwanPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Component")); 
	ProjectileSpwanPoint->SetupAttachment(TurretMesh);

}


void AMyPawn::HandleDestruction()
{
	//设置粒子效果
	if (DeathParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticles, GetActorLocation(), GetActorRotation());

	}
	//设置声音
	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
	}

	//设置抖动
	if (DeathCameraShakeClass)
	{
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathCameraShakeClass);
	}
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

}

void AMyPawn::RotatorTurret(FVector LookAtTarget)
{

	//两个位置的向量相减  得到它们之间的距离
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();

	FRotator LookAtRotation = FRotator(0.0f, ToTarget.Rotation().Yaw, 0.0f);
	TurretMesh->SetWorldRotation(LookAtRotation);

}

void AMyPawn::Fire()
{
	//获取炮塔组件位置
	FVector Location = ProjectileSpwanPoint->GetComponentLocation();
	FRotator Rotation = ProjectileSpwanPoint->GetComponentRotation();

	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
	if (Projectile)
	{
		Projectile->SetOwner(this);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Projectile"));
	}
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



