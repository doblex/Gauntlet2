// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Gauntlet2/Core/SubSystems/Quests/FQuestDetailRow.h"
#include "QuestWidget.generated.h"

/**
 * 
 */
class UTextBlock;
UCLASS()
class GAUNTLET2_API UQuestWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	// BindWidget looks for a widget with this exact name in your Blueprint
	UPROPERTY(meta = (BindWidget))
	UTextBlock* QuestTitleText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* QuestDescriptionText;

public:
	// Function to update the UI from your Quest System
	UFUNCTION(BlueprintCallable, Category = "Quest")
	void UpdateQuestDisplay(FQuestDetailRow QuestDetail);
};
