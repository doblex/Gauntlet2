// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gauntlet2/Actors/BaseClasses/BaseActivateableActor.h"
#include "Door.generated.h"

UCLASS()
class GAUNTLET2_API ADoor : public ABaseActivateableActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	float Timer;
	
	UStaticMeshComponent* DoorMeshComponent;
	
	TArray<USceneComponent*> DoorPoints;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door")
	FName DoorMeshTag = FName("DoorMesh");
	
	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door", meta = (MakeEditWidget = true))
	float DoorSpeed = 2.f;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Activatable_Implementation(bool activate) override;
};
