// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGameInstance.h"

#include "Kismet/GameplayStatics.h"

void UCoreGameInstance::GoToMenu()
{
	if (MenuReference.IsNull()) return;
	
	UGameplayStatics::OpenLevelBySoftObjectPtr( GetWorld(),MenuReference);
}

void UCoreGameInstance::GoToGame()
{
	if (LevelReference.IsNull()) return;
	
	UGameplayStatics::OpenLevelBySoftObjectPtr( GetWorld(),LevelReference);
}