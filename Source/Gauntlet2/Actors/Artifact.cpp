// Fill out your copyright notice in the Description page of Project Settings.


#include "Artifact.h"

#include "Gauntlet2/Components/InteractionColorChangeComponent.h"

// Sets default values
AArtifact::AArtifact()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AArtifact::BeginPlay()
{
	Super::BeginPlay();
	
	UInteractionColorChangeComponent* comp = 
		Cast<UInteractionColorChangeComponent>(
			GetComponentByClass(UInteractionColorChangeComponent::StaticClass())
			);
	
	if (IsValid(comp))
	{
		comp->OnInteraction.BindDynamic(this, &AArtifact::OnInteraction);
	}
}

void AArtifact::OnInteraction()
{
	APawn* PG = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PG) return;

	USkeletalMeshComponent* PGMesh =
		PG->FindComponentByClass<USkeletalMeshComponent>();

	if (!PGMesh) return;

	AttachToComponent(
		PGMesh,
		FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		TEXT("VB_Hand_r")
	);
}

// Called every frame
void AArtifact::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

