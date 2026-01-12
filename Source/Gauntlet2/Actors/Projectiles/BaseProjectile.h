// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gauntlet2/Core/SubSystems/ObjectPooler/ObjectPoolInterface.h"
#include "BaseProjectile.generated.h"

class UObjectPoolerSubsystem;

UCLASS()
class GAUNTLET2_API ABaseProjectile : public AActor, public IObjectPoolInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveProjectile(float DeltaTime);
	void TryDeactivate(float DeltaTime);
	void SetActive(bool Active);
	
	float ActiveTimer = 0.0f;
	bool bActive = false;

	UObjectPoolerSubsystem* ObjPoolSys;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile")
	float DespawnTimer = 4.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile")
	float Speed = 100.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile")
	float KnockBackPower = 100.f;
	
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void NativeActivate(FObjectPoolActivateData Data) override;

	virtual void NativeDeactivate(FObjectPoolDeactivateData Data) override;
	
	
};
