// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OrbitatingPlatform.generated.h"

UCLASS()
class GAUNTLET2_API AOrbitatingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOrbitatingPlatform();
	void SetPlatformPos(float DeltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	bool bCanRotate;
	
	TArray<USceneComponent*> PlatformsActors;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformAnimation")
	float AnimationSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformAnimation")
	float Distance;
	
	UFUNCTION()
	void OnActivation(bool bActivate);
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
