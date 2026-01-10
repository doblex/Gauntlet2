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
	
	bool bIsActive;
	
	UMaterialInstanceDynamic* DynamicMaterialInstance;
	USceneComponent* ColorRootComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Activable Component")
	UMaterialInterface* ParentMsaterial;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Activable Component")
	FColor BaseColor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Activable Component")
	FColor InteractColor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Activable Component")
	FName ColorRootTag = FName("ColorRoot");
	
	void ChangeColor(bool Active);
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Activatable_Implementation(bool activate) override;
	
	
};
