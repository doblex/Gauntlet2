// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FirstPersonCharater.h"
#include "EnhancedInputComponent.h"

// Sets default values
ACPP_FirstPersonCharater::ACPP_FirstPersonCharater()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_FirstPersonCharater::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_FirstPersonCharater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_FirstPersonCharater::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	if (!EnhancedInput) return;
	
	if (MoveAction)
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPP_FirstPersonCharater::Move);
	}
	
	if (LookAction)
	{
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPP_FirstPersonCharater::Look);
	}
	
	if (JumpAction)
	{
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ACPP_FirstPersonCharater::StartJump);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACPP_FirstPersonCharater::StopJump);
	}
	
	if (InteractAction)
	{
		EnhancedInput->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ACPP_FirstPersonCharater::Interact);
	}

}

void ACPP_FirstPersonCharater::Move(const struct FInputActionValue& Value)
{
	const FVector2D Input = Value.Get<FVector2D>();
	
	AddMovementInput(GetActorForwardVector(), Input.Y);
	AddMovementInput(GetActorRightVector(), Input.X);
}

void ACPP_FirstPersonCharater::Look(const struct FInputActionValue& Value)
{
	const FVector2D Input = Value.Get<FVector2D>();	
	
	AddControllerYawInput(Input.X);
	AddControllerPitchInput(Input.Y);
}

void ACPP_FirstPersonCharater::StartJump(const struct FInputActionValue& Value)
{
	Jump();
}

void ACPP_FirstPersonCharater::StopJump(const struct FInputActionValue& Value)
{
	StopJumping();
}

void ACPP_FirstPersonCharater::Interact(const struct FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("ACPP_FirstPersonCharater::Interact"));
}

