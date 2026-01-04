// Fill out your copyright notice in the Description page of Project Settings.


#include "ActivableColorChangeComponent.h"


// Sets default values for this component's properties
UActivableColorChangeComponent::UActivableColorChangeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActivableColorChangeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActivableColorChangeComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UActivableColorChangeComponent::Activatable_Implementation(bool activate)
{
	IActivatable::Activatable_Implementation(activate);
	
	bIsActive = !bIsActive;
	 
	if (DynamicMaterialInstance)
	{
		DynamicMaterialInstance->SetVectorParameterValue("Color",  bIsActive ? InteractColor : BaseColor);
	}
	
	OnActivation.Execute(activate);
}

