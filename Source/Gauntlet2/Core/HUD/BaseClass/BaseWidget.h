#pragma once

class UWidget;
class UPanelWidget;

// Simple enum for managing removal
enum ERemoveWidgetMode
{
	ERemoveWidgetMode_Last,
	ERemoveWidgetMode_All,
};

// Simple class for managing pushing and popping on a panel
class BaseWidget
{
public:
	UPanelWidget* PanelWidget;
	TArray<UWidget*> WidgetMap;
	
	BaseWidget(UPanelWidget* PanelWidget);
	
	void PushWidget(UWidget* Widget);
	void PopWidget(UWidget* WidgetToRemove = nullptr);
	void PopAllWidget();
};
