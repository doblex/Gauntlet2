// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gauntlet2/Interfaces/Activatable.h"
#include "BaseActivateableActor.generated.h"

UCLASS()
class GAUNTLET2_API ABaseActivateableActor : public AActor, public IActivatable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseActivateableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void ChangeColor(bool Active);
	
	bool bIsActive;
	
	UMaterialInstanceDynamic* DynamicMaterialInstance;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Component")
	UMaterialInterface* ParentMsaterial;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Component")
	FColor BaseColor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Component")
	FColor InteractColor;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Activatable_Implementation(bool activate) override;
	
	
};
