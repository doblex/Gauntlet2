// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
	Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	for (auto Element : GetComponents())
	{
		if (Element->ComponentTags.Contains(TurretPivotTag))
		{
			TurretPivot = Cast<UStaticMeshComponent>(Element);
		}
	}
}

void ATurret::SetTurretRotation()
{
	if (bIsInactive) return;
	
	if (!Player) return;
	
	const FVector TurretLocation = TurretPivot->GetComponentLocation();
	FVector ToPlayer = Player->GetActorLocation() - TurretLocation;
	ToPlayer.Z = 0.0f;
	
	if (ToPlayer.Length() > Range)
	{
		bIsPlayerInRange = false;
	}
	else
	{
		bIsPlayerInRange = true;
		FRotator Rotation = FRotationMatrix::MakeFromX(ToPlayer).Rotator();
		Rotation.Pitch = 0.0f;
		Rotation.Roll = 0.0f;
	
		if (IsValid(TurretPivot))
		{
			TargetRotation = Rotation;
		}
	}
}

void ATurret::OnReActivation()
{
	if (!bIsInactive) return; 
	
	Activatable_Implementation(false);
}

void ATurret::Activatable_Implementation(bool activate)
{
	Super::Activatable_Implementation(activate);
	
	if (!activate)
	{
		bIsInactive = false;
		return;
	}
	
	if (IsValid(ColorChangeComponent))
	{
		GetWorld()->GetTimerManager().SetTimer
		(
			TimerHandle,
			this,
			&ATurret::OnReActivation,
			DeactiveDuration
			);
	}
	
	bIsInactive = true;
}

void ATurret::RotateToPlayerPos(float DeltaTime)
{
	if (!bIsPlayerInRange)
	{
		if (timer < 0.f)
		{
			timer = RandomChangeTimer;
		
			FVector EulerRotation = FVector(0,0, FMath::RandRange(-180.0f, 180.0f));
		
			TargetRotation = FRotator::MakeFromEuler(EulerRotation);
		}
		
		timer -= DeltaTime;
	}
	
	if (!IsValid(TurretPivot)) return;
	
	FRotator NewRotation = FMath::RInterpTo(
	TurretPivot->GetRelativeRotation(),
	TargetRotation,
	DeltaTime,
	MovementSpeed
);
	
	TurretPivot->SetRelativeRotation(NewRotation);
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetTurretRotation();
	RotateToPlayerPos(DeltaTime);
	DrawDebugSphere(GetWorld(), GetActorLocation(), Range, 20, bIsPlayerInRange ? FColor::Emerald : FColor::Yellow);
}

