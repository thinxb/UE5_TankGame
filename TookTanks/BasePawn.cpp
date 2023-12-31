// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"

//#include "Projectile.h"
//#include "Engine/World.h"
//#include "Components/CapsuleComponent.h"
//#include "Kismet/GameplayStatics.h"
//#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	//RootComponent = CapsuleComp;

	//BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	//BaseMesh->SetupAttachment(RootComponent);

	//TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	//TurretMesh->SetupAttachment(BaseMesh);

	//ProjectileSpwanPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Component")); 
	//ProjectileSpwanPoint->SetupAttachment(TurretMesh);
}

void ABasePawn::HandleDestruction()
{
	//设置粒子效果
	//if (DeathParticles)
	//{
	//	UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticles, GetActorLocation(), GetActorRotation());

	//}
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasePawn::RotatorTurret(FVector LookAtTarget)
{

	//两个位置的向量相减  得到它们之间的距离
	//FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();

	//FRotator LookAtRotation = FRotator(0.0f, ToTarget.Rotation().Yaw, 0.0f);
	//TurretMesh->SetWorldRotation(LookAtRotation);

}

void ABasePawn::Fire()
{
	////获取炮塔组件位置
	//FVector Location = ProjectileSpwanPoint->GetComponentLocation();
	//FRotator Rotation = ProjectileSpwanPoint->GetComponentRotation();

	//auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
	//Projectile->SetOwner(this);
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

