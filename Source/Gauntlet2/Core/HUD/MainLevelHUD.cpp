// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevelHUD.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"

void AMainLevelHUD::Pause(bool bPause)
{
	if (!PauseMenuWidget) return;
	
	if (bPause)
	{
		Push(PauseMenuWidget);
		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(GetOwningPlayerController());
	}
	else
	{
		Pop(PauseMenuWidget);
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(GetOwningPlayerController());
	}
	
	APlayerController* PC = Cast<APlayerController>(GetOwningPlayerController());

	if (PC)
	{
		PC->bShowMouseCursor = bPause;
	}
	
	UGameplayStatics::SetGamePaused(GetWorld(), bPause);
	
	
}
