// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestWidget.h"

#include "Components/TextBlock.h"

void UQuestWidget::UpdateQuestDisplay(FQuestDetailRow QuestDetail)
{
	if (QuestTitleText)
	{
		QuestTitleText->SetText(FText::FromName(QuestDetail.QuestName)); 
	}
	
	if (QuestDescriptionText)
	{
		QuestDescriptionText->SetText(QuestDetail.QuestDescription);
	}
}
