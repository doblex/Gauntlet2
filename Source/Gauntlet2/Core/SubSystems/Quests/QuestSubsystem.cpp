// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSubsystem.h"

#include "UQuestEffectDataAsset.h"
#include "NiagaraFunctionLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "Gauntlet2/Core/DevSettings/QuestDevSettings.h"
#include "Kismet/GameplayStatics.h"


void UQuestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	LoadQuestTable();
	QuestIndex = 0;
	
	UE_LOG(LogTemp, Warning, TEXT("UQuestSubsystem::Initialize()"));
}

void UQuestSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UQuestSubsystem::LoadQuestTable()
{
	const UQuestDevSettings* Settings = GetDefault<UQuestDevSettings>();
	if (Settings)
	{
		TSoftObjectPtr<UDataTable> TablePtr = Settings->QuestDataTable;
		FStreamableManager& ManagedLoader = UAssetManager::GetStreamableManager();
		
		ManagedLoader.RequestAsyncLoad(
			TablePtr.ToSoftObjectPath(),
			FStreamableDelegate::CreateUObject(this, &UQuestSubsystem::OnTableLoaded, TablePtr)
		);
	}
}

void UQuestSubsystem::OnTableLoaded( TSoftObjectPtr<UDataTable> TablePtr)
{
	QuestTable = TablePtr.Get();
	
	if (QuestTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("QuestSubsystem: Table Loaded Succesfully"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("QuestSubsystem: Table Loaded Failed"));
	}
}

void UQuestSubsystem::CompleteQuest(AActor* Actor)
{
	FQuestDetailRow* CurrentRow = nullptr;
	
	if (GetCurrentQuest(CurrentRow))
	{
		if (IsValid(CurrentRow->QuestEffects))
		{
		
		UQuestEffectDataAsset* Effects = CurrentRow->QuestEffects;
		
		
			if (!Effects->CompletionSound.IsNull())
			{
				//Load Effect from memory
				USoundBase* Sound = Effects->CompletionSound.LoadSynchronous();
				UGameplayStatics::PlaySound2D(this, Sound);
			}
		
			if (!Effects->CompletionVFX.IsNull())
			{
				//Load Effect from memory
				UNiagaraSystem* Effect = Effects->CompletionVFX.LoadSynchronous();
        
				// Spawn on the actor that completes the quest
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Effect, Actor->GetActorLocation());
			}
		}
	}
	
	OnQuestCompleted.ExecuteIfBound();
}

bool UQuestSubsystem::GetCurrentQuest( FQuestDetailRow*& Out)
{
	static const FString ContextString(TEXT("UQuestSubsystem::GetCurrentQuest"));
	Out = QuestTable->FindRow<FQuestDetailRow>(FName("0"),ContextString);
	return Out != nullptr;
}

FQuestDetailRow& UQuestSubsystem::GetCurrentQuest()
{
	static const FString ContextString(TEXT("UQuestSubsystem::GetCurrentQuest"));
	FQuestDetailRow* CurrentRow = QuestTable->FindRow<FQuestDetailRow>(FName("0"),ContextString);
	return *CurrentRow;
}
