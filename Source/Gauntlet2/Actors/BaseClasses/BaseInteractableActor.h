// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gauntlet2/Interfaces/Interactable.h"
#include "BaseInteractableActor.generated.h"

UCLASS()
class GAUNTLET2_API ABaseInteractableActor : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseInteractableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void Interact_Implementation() override;
	

	
	bool bIsActive;
	
	UMaterialInstanceDynamic* DynamicMaterialInstance;
	USceneComponent* ColorRootComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Component")
	UMaterialInterface* ParentMsaterial;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Component")
	FColor BaseColor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Component")
	FColor InteractColor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Component")
	FName ColorRootTag = FName("ColorRoot");
	
	void ChangeColor(bool Active);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
