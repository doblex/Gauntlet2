// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gauntlet2/Actors/BaseClasses/BaseActivateableActor.h"
#include "OrbitatingPlatform.generated.h"

UCLASS()
class GAUNTLET2_API AOrbitatingPlatform : public ABaseActivateableActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOrbitatingPlatform();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SpawnPlatforms();
	void SetPlatformPos(float DeltaTime);
	
	bool bCanRotate;
	
	float AngleStep = 0;
	
	TArray<AActor*> PlatformsActors;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Orbiting Platform")
	TSubclassOf<AActor> PlatformActor;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Orbiting Platform")
	int PlatformNumber = 5;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbiting Platform")
	float AnimationSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbiting Platform")
	float Distance;
	
	void Activatable_Implementation(bool activate) override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
