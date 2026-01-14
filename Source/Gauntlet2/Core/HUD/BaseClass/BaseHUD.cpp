// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseHUD.h"
#include "BaseWidget.h"
#include "Components/PanelWidget.h"
#include "Components/Widget.h"


void ABaseHUD::BeginPlay()
{
	Super::BeginPlay();
	
	if (!IsValid(HUDBaseClass)) return;
	
	HudWidget = CreateWidget<UUserWidget>(GetWorld(), HUDBaseClass);
	
	HudWidget->AddToViewport();

	UPanelWidget* Panel = Cast<UPanelWidget>(HudWidget->GetWidgetFromName(PanelName));
	
	if (Panel)
	{
		Widget = new BaseWidget(Panel);
	}
}

void ABaseHUD::Push(UUserWidget* WidgetToAdd)
{
	if (Widget)
	{
		Widget->PushWidget(WidgetToAdd);
	}
}

// remove WidgetToRemove from the parent, if it is null it removes the last added element
void ABaseHUD::Pop(UUserWidget* WidgetToRemove)
{
	if (Widget)
	{
		Widget->PopWidget(WidgetToRemove);
	}
}

void ABaseHUD::PopAll()
{
	Widget->PopAllWidget();
}
