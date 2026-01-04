// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseColorChangeComponent.h"
#include "Gauntlet2/Interfaces/Activatable.h"
#include "ActivableColorChangeComponent.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnActivation, bool, activate);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAUNTLET2_API UActivableColorChangeComponent : public UBaseColorChangeComponent, public IActivatable
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UActivableColorChangeComponent();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FOnActivation OnActivation;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	void Activatable_Implementation(bool activate) override;
};
