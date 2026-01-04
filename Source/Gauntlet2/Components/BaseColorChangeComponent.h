// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseColorChangeComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAUNTLET2_API UBaseColorChangeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBaseColorChangeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	bool bIsActive;
	
	UMaterialInstanceDynamic* DynamicMaterialInstance;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Component")
	UMaterialInterface* ParentMsaterial;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Component")
	FColor BaseColor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Component")
	FColor InteractColor;
};
