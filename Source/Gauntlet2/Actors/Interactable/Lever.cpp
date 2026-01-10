// Fill out your copyright notice in the Description page of Project Settings.


#include "Lever.h"

#include "Gauntlet2/Interfaces/Activatable.h"

// Sets default values
ALever::ALever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALever::BeginPlay()
{
	Super::BeginPlay();
	bIsActive = false;
	CurrentIndex = 0;
	
	TArray<UActorComponent*> PointsRef 
	= GetComponentsByTag(USceneComponent::StaticClass(), FName("PointRef"));

	for (UActorComponent* Point : PointsRef)
	{
		USceneComponent* PointSceneComponent = Cast<USceneComponent>(Point);
		
		if (IsValid(PointSceneComponent))
		{
			Points.Add(PointSceneComponent);
		}
	}
	
	TArray<UActorComponent*> StaticMeshComponents =
		GetComponentsByTag(UMeshComponent::StaticClass(), FName("Lever"));
	
	if (StaticMeshComponents.Num() > 0)
	{
		LeverStaticMesh = Cast<UStaticMeshComponent>(StaticMeshComponents[0]);
	}
}

void ALever::ActivateObjects(bool newState)
{
	for (auto Element : ObjectsToActivate)
	{
		if (IsValid(Element))
		{
			IActivatable::Execute_Activatable(Element, bIsActive);
		}
	}
}

void ALever::Interact_Implementation()
{
	if (bIsButton)
	{
		if (bIsActive) return;
	}
	
	Super::Interact_Implementation();

	Timer = 0.0f;
	
	ActivateObjects(true);
	
	if (bIsButton)
	{
		GetWorld()->GetTimerManager().SetTimer
		(
		TimerHandle,
		this,
		&ALever::ResetInteraction,
		ButtonReactivationTime
		);
	}
}

void ALever::ResetInteraction()
{
	Super::Interact_Implementation();
	ActivateObjects(false);
	Timer = 0.0f;
}

// Called every frame
void ALever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Timer > 1.f) return;
	
	Timer += DeltaTime;
	FVector From = bIsActive ? Points[0]->GetRelativeLocation() : Points[1]->GetRelativeLocation();
	FVector To = bIsActive ? Points[1]->GetRelativeLocation() : Points[0]->GetRelativeLocation();
	
	FVector CurrentLocation = FMath::Lerp<FVector>(From, To, Timer * LeverSpeed); 
	
	LeverStaticMesh->SetRelativeLocation(CurrentLocation);
}

