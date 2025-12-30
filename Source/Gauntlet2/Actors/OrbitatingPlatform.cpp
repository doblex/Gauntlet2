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
	
	
	root->GetChildrenComponents(false, PlatformsActors);
	
	float angle = 360/PlatformsActors.Num();
	float x = 0;
	float y = 0;
	FVector pos = FVector(0,0,0);
	
	for (int i = 0; i < PlatformsActors.Num(); i++)
	{
		x =  FMath::Sin(angle*i) * Distance;
		y =  FMath::Cos(angle*i) * Distance;
		pos.Set(x, y, 0);
		PlatformsActors[i]->SetRelativeLocation(pos);
	}
}

// Called every frame
void AOrbitatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	DrawDebugSphere(GetWorld(), GetActorLocation(), 2.f, 10, FColor::Purple);
}

