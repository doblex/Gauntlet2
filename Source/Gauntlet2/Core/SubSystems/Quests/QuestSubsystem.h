// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FQuestDetailRow.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestSubsystem.generated.h"

DECLARE_DYNAMIC_DELEGATE(FOnQuestCompleted);

UCLASS()
class GAUNTLET2_API UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
protected:
	void LoadQuestTable();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UFUNCTION()
	void OnTableLoaded(TSoftObjectPtr<UDataTable> TablePtr);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestSubsystem")
	UDataTable* QuestTable;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestSubsystem")
	int QuestIndex = 0;
	
public:
	FOnQuestCompleted OnQuestCompleted;
	
	void CompleteQuest(AActor* Actor);
	bool GetCurrentQuest(FQuestDetailRow*& Out);
	
};
