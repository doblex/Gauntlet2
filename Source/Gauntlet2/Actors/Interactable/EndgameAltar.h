// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gauntlet2/Actors/BaseClasses/BaseInteractableActor.h"
#include "EndgameAltar.generated.h"

UCLASS()
class GAUNTLET2_API AEndgameAltar : public ABaseInteractableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEndgameAltar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bHasArtifact = false;
	
	USceneComponent* PivotComponent;
	FTimerHandle TimerHandle;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Interaction")
	FName PivotTag;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Interaction")
	float SecondsToEndGame = 5.f;
	
	UFUNCTION()
	void EndGame();
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Interact_Implementation() override;
};
