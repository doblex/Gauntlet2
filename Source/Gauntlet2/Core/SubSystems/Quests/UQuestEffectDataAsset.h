// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraSystem.h"
#include "UQuestEffectDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAUNTLET2_API UQuestEffectDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UQuestEffectDataAsset();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	TSoftObjectPtr<UNiagaraSystem> CompletionVFX;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	TSoftObjectPtr<USoundBase> CompletionSound;
};
