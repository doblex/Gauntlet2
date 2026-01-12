// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gauntlet2/Actors/BaseClasses/BaseActivateableActor.h"
#include "Turret.generated.h"

class UObjectPoolerSubsystem;

UCLASS()
class GAUNTLET2_API ATurret : public ABaseActivateableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetTurretRotation();
	void RotateToPlayerPos(float DeltaTime);
	void Shoot(float DeltaTime);
	
	bool bIsPlayerInRange = false;
	
	float RotationTimer;
	float ShootingTimer;
	
	AActor* Player;
	UStaticMeshComponent* TurretPivot;
	USceneComponent* ShootingPoint;
	FRotator TargetRotation;
	FTimerHandle TimerHandle;
	UObjectPoolerSubsystem* ObjPoolSys;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret|Movement")
	float RotationSpeed = 2.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret|Movement")
	float RandomChangeTimer = 5.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret")
	FName TurretPivotTag = "TurretPivot";
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret")
	FName ShotingPointTag = "ShootingPoint";
	
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret|Property")
	float Range;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret|Property")
	float DeactiveDuration = 10.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret|Property")
	bool bIsInactive;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Turret|Shooting")
	float ShootingTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret|Shooting")
	TSubclassOf<AActor> ActorToSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret|Shooting")
	FVector SpawnScale = FVector(1.0f, 1.0f, 1.0f);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret|Shooting")
	int32 PoolSize = 1;
	
	UFUNCTION()
	void OnReActivation();
	
	virtual void Activatable_Implementation(bool activate) override;
	
public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
