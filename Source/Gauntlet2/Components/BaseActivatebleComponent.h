// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gauntlet2/Interfaces/Activatable.h"
#include "BaseActivatebleComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAUNTLET2_API UBaseActivatebleComponent : public UActorComponent, public IActivatable
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBaseActivatebleComponent();

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
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	
	virtual void Activatable_Implementation(bool activate) override;
};
