// Fill out your copyright notice in the Description page of Project Settings.


#include "Artifact.h"

#include "Gauntlet2/Characters/CPP_ThirdPersonCharater.h"

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
}

void AArtifact::Interact_Implementation()
{
	Super::Interact_Implementation();
	
	APawn* PG = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PG) return;

	ACPP_ThirdPersonCharater* Charater = Cast<ACPP_ThirdPersonCharater>(PG);
	if (!Charater) return;
	
	
	USkeletalMeshComponent* PGMesh =
		Charater->FindComponentByClass<USkeletalMeshComponent>();

	if (!PGMesh) return;

	SetActorEnableCollision(false);
	
	AttachToComponent(
		PGMesh,
		FAttachmentTransformRules::SnapToTargetIncludingScale,
		TEXT("hand_r")
	);
	
	Charater->Artifact = this;
}

// Called every frame
void AArtifact::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

