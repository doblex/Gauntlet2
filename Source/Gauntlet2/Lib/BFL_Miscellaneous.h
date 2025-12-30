// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BFL_Miscellaneous.generated.h"

/**
 * 
 */
UCLASS()
class GAUNTLET2_API UBFL_Miscellaneous : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static void CollectStaticMeshComponents(
	USceneComponent* CurrentComponent,
	TArray<UStaticMeshComponent*>& OutMeshes
);
};
