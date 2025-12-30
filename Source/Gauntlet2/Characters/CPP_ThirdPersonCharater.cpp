// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ThirdPersonCharater.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/GameModeBase.h"

// Sets default values
ACPP_ThirdPersonCharater::ACPP_ThirdPersonCharater()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_ThirdPersonCharater::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_ThirdPersonCharater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_ThirdPersonCharater::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	if (!EnhancedInput) return;
	
	if (MoveAction)
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPP_ThirdPersonCharater::Move);
	}
	
	if (LookAction)
	{
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPP_ThirdPersonCharater::Look);
	}
	
	if (JumpAction)
	{
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ACPP_ThirdPersonCharater::StartJump);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACPP_ThirdPersonCharater::StopJump);
	}
	
	if (PauseAction)
	{
		EnhancedInput->BindAction(PauseAction,ETriggerEvent::Triggered, this, &ACPP_ThirdPersonCharater::Move);
	}
	
	if (InteractAction)
	{
		EnhancedInput->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ACPP_ThirdPersonCharater::Interact);
	}

}

void ACPP_ThirdPersonCharater::Move(const struct FInputActionValue& Value)
{
	const FVector2D Input = Value.Get<FVector2D>();
	
	AddMovementInput(GetActorForwardVector(), Input.Y);
	AddMovementInput(GetActorRightVector(), Input.X);
}

void ACPP_ThirdPersonCharater::Look(const FInputActionValue& Value)
{
	const FVector2D Input = Value.Get<FVector2D>();	
	
	AddControllerYawInput(Input.X);
	AddControllerPitchInput(Input.Y);
}

void ACPP_ThirdPersonCharater::StartJump(const FInputActionValue& Value)
{
	Jump();
}

void ACPP_ThirdPersonCharater::StopJump(const FInputActionValue& Value)
{
	StopJumping();
}

void ACPP_ThirdPersonCharater::Pause(const FInputActionValue& value)
{
	//TODO: PAUSE the Game
}

void ACPP_ThirdPersonCharater::Interact(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("ACPP_FirstPersonCharater::Interact"));
}

void ACPP_ThirdPersonCharater::FellOutOfWorld(const class UDamageType& dmgType)
{
	Respawn();
}

void ACPP_ThirdPersonCharater::Respawn()
{
	AGameModeBase* Gm = GetWorld()->GetAuthGameMode();
	if (!IsValid(Gm)) return;
	
	AActor* Start = Gm->ChoosePlayerStart(GetController());
		
	if (!IsValid(Start)) return;
	
	SetActorLocation(Start->GetActorLocation());
}

