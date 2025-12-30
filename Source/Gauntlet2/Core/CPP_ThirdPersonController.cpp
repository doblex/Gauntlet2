// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ThirdPersonController.h"
#include "EnhancedInputSubsystems.h"


void ACPP_ThirdPersonController::BeginPlay()
{
	Super::BeginPlay();

	if (!InputMapping) return;
	

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (Subsystem)
	{
		Subsystem->AddMappingContext(InputMapping, 0);
	}
}