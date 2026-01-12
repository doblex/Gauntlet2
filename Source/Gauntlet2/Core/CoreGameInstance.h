// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CoreGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAUNTLET2_API UCoreGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> LevelReference;
	
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> MenuReference;

public:
	UFUNCTION(BlueprintCallable)
	void GoToMenu();
	
	UFUNCTION(BlueprintCallable)
	void GoToGame();
};
