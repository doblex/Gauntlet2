// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseColorChangeComponent.h"
#include "Gauntlet2/Lib/BFL_Miscellaneous.h"


// Sets default values for this component's properties
UBaseColorChangeComponent::UBaseColorChangeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBaseColorChangeComponent::BeginPlay()
{
	Super::BeginPlay();
	
	DynamicMaterialInstance = UMaterialInstanceDynamic::Create(ParentMsaterial, this);
	
	if (DynamicMaterialInstance)
	{
		DynamicMaterialInstance->SetVectorParameterValue("Color", BaseColor);
	}
	
	TArray<UStaticMeshComponent*> StaticMeshes;
	
	UBFL_Miscellaneous::CollectStaticMeshComponents(GetOwner()->GetRootComponent(), StaticMeshes);
	
	for (auto Component : StaticMeshes)
	{
		Component->SetMaterial(0, DynamicMaterialInstance);
	}
}

