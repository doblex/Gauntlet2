// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitatingPlatform.h"

#include "Gauntlet2/Components/ActivableColorChangeComponent.h"


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
	
	UActivableColorChangeComponent* comp = 
		Cast<UActivableColorChangeComponent>(
			GetComponentByClass(UActivableColorChangeComponent::StaticClass())
			);
	
	if (IsValid(comp))
	{
		comp->OnActivation.BindDynamic(this, &AOrbitatingPlatform::OnActivation);
		bCanRotate = false;
	}
	
	root->GetChildrenComponents(false, PlatformsActors);
	
	SetPlatformPos(0);
}

void AOrbitatingPlatform::OnActivation(bool bActivate)
{
	bCanRotate = bActivate;
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

void AOrbitatingPlatform::SetPlatformPos(float DeltaTime)
{
	float FrameOffset = DeltaTime * AnimationSpeed;
	
	float angle = 360/PlatformsActors.Num();
	float x = 0;
	float y = 0;
	FVector pos = FVector(0,0,0);
	
	for (int i = 0; i < PlatformsActors.Num(); i++)
	{
		x =  FMath::Sin(angle*i + FrameOffset) * Distance;
		y =  FMath::Cos(angle*i + FrameOffset) * Distance;
		pos.Set(x, y, 0);
		PlatformsActors[i]->SetRelativeLocation(pos);
	}
}
