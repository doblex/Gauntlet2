// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CoreGameInstance.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE(FOnLevelLoaded);

UCLASS()
class GAUNTLET2_API UCoreGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UWorld> LevelReference;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UWorld> MenuReference;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FOnLevelLoaded OnLevelLoaded;
	
public:
	UFUNCTION(BlueprintCallable)
	void GoToMenu();
	
	UFUNCTION(BlueprintCallable)
	void GoToGame();
};
