// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseActivateableActor.h"

#include "Gauntlet2/Lib/BFL_Miscellaneous.h"


// Sets default values
ABaseActivateableActor::ABaseActivateableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseActivateableActor::BeginPlay()
{
	Super::BeginPlay();
	
	DynamicMaterialInstance = UMaterialInstanceDynamic::Create(ParentMsaterial, this);
	
	if (DynamicMaterialInstance)
	{
		DynamicMaterialInstance->SetVectorParameterValue("Color", BaseColor);
	}
	
	ColorRootComponent = 
		Cast<USceneComponent>(
			GetComponentsByTag(USceneComponent::StaticClass() ,ColorRootTag)[0]
			);
	
	TArray<UStaticMeshComponent*> StaticMeshes;
	if (IsValid(ColorRootComponent))
	{
		UBFL_Miscellaneous::CollectStaticMeshComponents(ColorRootComponent, StaticMeshes);
	}
	else
	{
		UBFL_Miscellaneous::CollectStaticMeshComponents(GetRootComponent(), StaticMeshes);
	}
	
	for (auto Component : StaticMeshes)
	{
		Component->SetMaterial(0, DynamicMaterialInstance);
	}
}

// Called every frame
void ABaseActivateableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseActivateableActor::ChangeColor(bool Active)
{
	if (DynamicMaterialInstance)
	{
		DynamicMaterialInstance->SetVectorParameterValue("Color",  Active ? InteractColor : BaseColor);
	}
}

void ABaseActivateableActor::Activatable_Implementation(bool activate)
{
	IActivatable::Activatable_Implementation(activate);
	
	bIsActive = !bIsActive;
	 
	if (DynamicMaterialInstance)
	{
		DynamicMaterialInstance->SetVectorParameterValue("Color",  bIsActive ? InteractColor : BaseColor);
	}
}

