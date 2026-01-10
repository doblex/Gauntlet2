// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"


// Sets default values
ADoor::ADoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<UActorComponent*> PointsRef 
	= GetComponentsByTag(USceneComponent::StaticClass(), FName("PointRef"));

	for (UActorComponent* Point : PointsRef)
	{
		USceneComponent* PointSceneComponent = Cast<USceneComponent>(Point);
		
		if (IsValid(PointSceneComponent))
		{
			DoorPoints.Add(PointSceneComponent);
		}
	}
	
	
	TArray<UActorComponent*> meshes = 
		GetComponentsByTag(UStaticMeshComponent::StaticClass(), DoorMeshTag);
	
	if (meshes.Num() > 0)
	{
		DoorMeshComponent = Cast<UStaticMeshComponent>(meshes[0]);
	}
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (Timer > 1.f) return;
	
	FVector From = bIsActive ? DoorPoints[0]->GetRelativeLocation() : DoorPoints[1]->GetRelativeLocation();
	FVector To = bIsActive ? DoorPoints[1]->GetRelativeLocation() : DoorPoints[0]->GetRelativeLocation();
	
	FVector CurrentLocation = FMath::Lerp<FVector>(From, To, Timer * DoorSpeed); 
	
	if (IsValid(DoorMeshComponent))
	{
		DoorMeshComponent->SetRelativeLocation(CurrentLocation);
	}
	
	Timer += DeltaTime;
}

void ADoor::Activatable_Implementation(bool activate)
{
	Super::Activatable_Implementation(activate);
	Timer = 0.f;
}

