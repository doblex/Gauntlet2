// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseClass/BaseHUD.h"
#include "MainLevelHUD.generated.h"

/**
 * 
 */
UCLASS()
class GAUNTLET2_API AMainLevelHUD : public ABaseHUD
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HUD")
	UUserWidget* PauseMenuWidget;
	
public:
	UFUNCTION(BlueprintCallable, Category = "HUD")
	void Pause(bool bPause);
};
