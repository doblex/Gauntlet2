// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"

#include "GameFramework/Character.h"
#include "Gauntlet2/Core/SubSystems/ObjectPooler/ObjectPoolerSubsystem.h"


// Sets default values
ABaseProjectile::ABaseProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	ObjPoolSys = GetWorld()->GetGameInstance()->GetSubsystem<UObjectPoolerSubsystem>();
	
	OnActorBeginOverlap.AddDynamic(this, &ABaseProjectile::OnOverlapBegin);
}


// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TryDeactivate(DeltaTime);
	MoveProjectile(DeltaTime);
}

void ABaseProjectile::MoveProjectile(float DeltaTime)
{
	if (!bActive) return;
	
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * Speed * DeltaTime);
}

void ABaseProjectile::TryDeactivate(float DeltaTime)
{
	ActiveTimer += DeltaTime;
	
	if (ActiveTimer >= DespawnTimer)
	{
		FObjectPoolDeactivateData Data;
		NativeDeactivate(Data);
		ActiveTimer = 0.0f;
	}
}

void ABaseProjectile::SetActive(bool Active)
{
	SetActorTickEnabled(Active);
	SetActorEnableCollision(Active);
	SetActorHiddenInGame(!Active);
	
	bActive = Active;
}

void ABaseProjectile::NativeActivate(FObjectPoolActivateData Data)
{
	IObjectPoolInterface::NativeActivate(Data);

	FVector Location = Data.ObjectPoolTransform.GetLocation();
	FRotator Rotation = Data.ObjectPoolTransform.Rotator();
	FVector Scale = Data.ObjectPoolTransform.GetScale3D();
	
	SetActorLocationAndRotation(Location, Rotation);
	SetActorScale3D(Scale);
	
	SetActive(true);
	SetActorTickEnabled(true);
}

void ABaseProjectile::NativeDeactivate(FObjectPoolDeactivateData Data)
{
	IObjectPoolInterface::NativeDeactivate(Data);

	FVector Location = Data.ObjectPoolReturnTransform.GetLocation();
	FRotator Rotation = Data.ObjectPoolReturnTransform.Rotator();
	
	SetActive(false);
	SetActorLocationAndRotation(Location, Rotation);
	
	ObjPoolSys->ReturnObjectToPool(GetClass(), this);
	
	SetActorTickEnabled(false);
}

void ABaseProjectile::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		FVector fwd = GetActorForwardVector();
		FRotator rot = GetActorRotation();
		
		FVector PushDirection = fwd;
		PushDirection.Z = 0;
		PushDirection.Normalize();
		
		ACharacter* VictimCharacter = Cast<ACharacter>(OtherActor);
		
		if (VictimCharacter)
		{
			VictimCharacter->LaunchCharacter(PushDirection * KnockBackPower, false, true);
		}
		
		FObjectPoolDeactivateData Data;
		NativeDeactivate(Data);
		ActiveTimer = 0.0f;
	}
}


