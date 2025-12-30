// Fill out your copyright notice in the Description page of Project Settings.


#include "BFL_Miscellaneous.h"

void UBFL_Miscellaneous::CollectStaticMeshComponents(
	USceneComponent* CurrentComponent,
	TArray<UStaticMeshComponent*>& OutMeshes
)
{
	if (!CurrentComponent)
	{
		return;
	}

	// Check if this component is a StaticMeshComponent
	if (UStaticMeshComponent* StaticMeshComp =
		Cast<UStaticMeshComponent>(CurrentComponent))
	{
		OutMeshes.Add(StaticMeshComp);
	}

	// Recurse into children
	const TArray<USceneComponent*>& Children =
		CurrentComponent->GetAttachChildren();

	for (USceneComponent* Child : Children)
	{
		CollectStaticMeshComponents(Child, OutMeshes);
	}
}
