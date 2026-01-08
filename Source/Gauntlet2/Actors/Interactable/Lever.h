// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gauntlet2/Actors/BaseClasses/BaseInteractableActor.h"
#include "Lever.generated.h"

UCLASS()
class GAUNTLET2_API ALever : public ABaseInteractableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALever();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void ActivateObjects(bool newState);

	virtual void Interact_Implementation() override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Lever Options")
	float LeverSpeed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Lever Options")
	bool bIsButton;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Lever Options", meta=(EditCondition="bIsButton", EditConditionshow))
	float ButtonReactivationTime = 10.f;
	
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Lever Options")
	TArray<AActor*> ObjectsToActivate;
	
	UStaticMeshComponent* LeverStaticMesh;
	TArray<USceneComponent*> Points;
	FTimerHandle TimerHandle;
	
	int CurrentIndex = 0;
	float Timer;
	
	UFUNCTION()
	void ResetInteraction();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
