// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseColorChangeComponent.h"
#include "Gauntlet2/Interfaces/Interactable.h"
#include "InteractionColorChangeComponent.generated.h"

DECLARE_DYNAMIC_DELEGATE(FOnInteraction);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAUNTLET2_API UInteractionColorChangeComponent : public UBaseColorChangeComponent, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInteractionColorChangeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FOnInteraction OnInteraction;
	
	void Interact_Implementation() override;
};
