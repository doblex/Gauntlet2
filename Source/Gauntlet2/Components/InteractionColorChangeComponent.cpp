// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionColorChangeComponent.h"


// Sets default values for this component's properties
UInteractionColorChangeComponent::UInteractionColorChangeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractionColorChangeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractionColorChangeComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInteractionColorChangeComponent::Interact_Implementation()
{
	IInteractable::Interact_Implementation();
	
	bIsActive = !bIsActive;
	 
	if (DynamicMaterialInstance)
	{
		DynamicMaterialInstance->SetVectorParameterValue("Color",  bIsActive ? InteractColor : BaseColor);
	}
	
	OnInteraction.Execute();
}

