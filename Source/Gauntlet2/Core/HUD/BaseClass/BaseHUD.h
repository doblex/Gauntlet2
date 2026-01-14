// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PanelWidget.h"
#include "GameFramework/HUD.h"
#include "BaseHUD.generated.h"

class BaseWidget;
/**
 * 
 */
UCLASS(Abstract)
class GAUNTLET2_API ABaseHUD : public AHUD
{
	GENERATED_BODY()
	
protected: 
	UUserWidget* HudWidget;
	BaseWidget* Widget;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HUD")
	TSubclassOf<UUserWidget> HUDBaseClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HUD")
	FName PanelName = FName("Panel");
	
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "HUD")
	void Push(UUserWidget* WidgetToAdd);
	
	UFUNCTION(BlueprintCallable, Category = "HUD")
	void Pop(UUserWidget* WidgetToRemove = nullptr);
	
	UFUNCTION(BlueprintCallable, Category = "HUD")
	void PopAll();
};
