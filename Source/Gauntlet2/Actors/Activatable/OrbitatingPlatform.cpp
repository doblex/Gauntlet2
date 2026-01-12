// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitatingPlatform.h"


// Sets default values
AOrbitatingPlatform::AOrbitatingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOrbitatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	USceneComponent* root = GetRootComponent();
	
	//Ho necessità sia in radianti per come funziona seno e coseno
	AngleStep = (2.0f * PI)/PlatformNumber;
	bCanRotate = false;
	
	SpawnPlatforms();
}

void AOrbitatingPlatform::Activatable_Implementation(bool activate)
{
	Super::Activatable_Implementation(activate);
	
	bCanRotate = activate;
}

// Called every frame
void AOrbitatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bCanRotate)
	{
		SetPlatformPos(GetGameTimeSinceCreation());
	}
	
	DrawDebugSphere(GetWorld(), GetActorLocation(), 2.f, 10, FColor::Purple);
}

void AOrbitatingPlatform::SpawnPlatforms()
{
	const FActorSpawnParameters SpawnParameters;
	
	for (int i = 0; i < PlatformNumber; i++)
	{
		float x =  FMath::Sin(AngleStep * (i+1)) * Distance;
		float y =  FMath::Cos(AngleStep * (i+1)) * Distance;
		FVector pos = FVector(x, y, 0);
		FRotator rot = FRotator(0, 0, 0); 
		
		AActor* platform = GetWorld()->SpawnActor<AActor>(PlatformActor, pos, rot, SpawnParameters);
		
		platform->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		
		PlatformsActors.Add(platform);
	}
}

PRAGMA_DISABLE_OPTIMIZATION
void AOrbitatingPlatform::SetPlatformPos(float DeltaTime)
{
	//Trasformo l'offest in radianti
	float FrameOffset = FMath::DegreesToRadians(DeltaTime * AnimationSpeed);
	
	for (int i = 0; i < PlatformsActors.Num(); i++)
	{
		float x =  FMath::Sin(AngleStep * (i+1) + FrameOffset) * Distance;
		float y =  FMath::Cos(AngleStep * (i+1) + FrameOffset) * Distance;
		FVector pos = FVector(x, y, 0);
		PlatformsActors[i]->SetActorRelativeLocation(pos);
	}
}
PRAGMA_ENABLE_OPTIMIZATION
