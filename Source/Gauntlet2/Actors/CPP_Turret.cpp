// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Turret.h"

#include "Gauntlet2/Components/ActivableColorChangeComponent.h"

// Sets default values
ACPP_Turret::ACPP_Turret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Turret::BeginPlay()
{
	Super::BeginPlay();
	
	Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	UActivableColorChangeComponent* comp = 
		Cast<UActivableColorChangeComponent>(
			GetComponentByClass(UActivableColorChangeComponent::StaticClass())
			);
	
	if (IsValid(comp))
	{
		comp->OnActivation.BindDynamic(this, &ACPP_Turret::OnActivation);
	}
	
	for (auto Element : GetComponents())
	{
		if (Element->ComponentTags.Contains(TurretPivotTag))
		{
			TurretPivot = Cast<UStaticMeshComponent>(Element);
		}
	}
}

void ACPP_Turret::SetTurretRotation()
{
	if (!IsActive) return;
	
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

void ACPP_Turret::OnActivation(bool bActivate)
{
	IsActive = bActivate;
}

void ACPP_Turret::RotateToPlayerPos(float DeltaTime)
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
void ACPP_Turret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetTurretRotation();
	RotateToPlayerPos(DeltaTime);
	DrawDebugSphere(GetWorld(), GetActorLocation(), Range, 20, bIsPlayerInRange ? FColor::Emerald : FColor::Yellow);
}

void ACPP_Turret::SetActive(bool Active)
{
	IsActive = Active;
}

