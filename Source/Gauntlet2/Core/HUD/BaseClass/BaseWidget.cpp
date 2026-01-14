#include "BaseWidget.h"
#include "Components/PanelWidget.h"
#include "Components/Widget.h"

BaseWidget::BaseWidget(UPanelWidget* PanelWidget)
{
	this->PanelWidget = PanelWidget;
	WidgetMap = TArray<UWidget*>();
}

void BaseWidget::PushWidget(UWidget* Widget)
{
	if (WidgetMap.Contains(Widget)) return;
		
	PanelWidget->AddChild(Widget);
	WidgetMap.Push(Widget);
}

void BaseWidget::PopWidget(UWidget* WidgetToRemove)
{
	if (!WidgetToRemove)
	{
		WidgetToRemove = WidgetMap.Pop();
		PanelWidget->RemoveChild(WidgetToRemove);
	}
	
	if (!WidgetMap.Contains(WidgetToRemove)) return;
	
	WidgetMap.Remove(WidgetToRemove);
	PanelWidget->RemoveChild(WidgetToRemove);
}

void BaseWidget::PopAllWidget()
{
	for (auto Element : WidgetMap)
	{
		PanelWidget->RemoveChild(Element);
	}
}
