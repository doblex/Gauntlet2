// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FQuestDetailRow.generated.h"

class UQuestEffectDataAsset;


USTRUCT(BlueprintType)
struct FQuestDetailRow : public FTableRowBase
{
	GENERATED_BODY()
    
public:
	// Constructor to set defaults
	FQuestDetailRow() 
		: QuestName("")
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestData")
	FName QuestName;
    
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestData")
	FText QuestDescription;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestData")
	UQuestEffectDataAsset* QuestEffects;
};
