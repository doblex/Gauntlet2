// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gauntlet2/Interfaces/Interactable.h"
#include "CPP_Turret.generated.h"

UCLASS()
class GAUNTLET2_API ACPP_Turret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Turret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetTurretRotation();
	
	AActor* Player;
	UStaticMeshComponent* TurretPivot;
	FRotator TargetRotation;
	
	bool bIsPlayerInRange = false;
	
	float timer;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret|Movement")
	float MovementSpeed = 2.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret|Movement")
	float RandomChangeTimer = 5.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret")
	FName TurretPivotTag = "TurretPivot";
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret|Property")
	float Range;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret|Property")
	float ShootingTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret|Property")
	bool IsActive;
	
public:
	void RotateToPlayerPos(float DeltaTime);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetActive(bool Active);
};
