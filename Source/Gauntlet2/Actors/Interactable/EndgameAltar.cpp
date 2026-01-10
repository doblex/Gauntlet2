// Fill out your copyright notice in the Description page of Project Settings.


#include "EndgameAltar.h"

#include "Artifact.h"
#include "Gauntlet2/Characters/CPP_ThirdPersonCharater.h"
#include "Gauntlet2/Core/SubSystems/Quests/QuestSubsystem.h"


// Sets default values
AEndgameAltar::AEndgameAltar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEndgameAltar::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<UActorComponent*> comps;
	comps = GetComponentsByTag(USceneComponent::StaticClass(),PivotTag);
	
	if (comps.Num() != 0)
	{
		PivotComponent = Cast<USceneComponent>(comps[0]);
	}
}

void AEndgameAltar::Interact_Implementation()
{
	Super::Interact_Implementation();
	
	APawn* PG = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PG) return;
	
	ACPP_ThirdPersonCharater* Charater = Cast<ACPP_ThirdPersonCharater>(PG);
	
	if (Charater->Artifact == nullptr) return;
	
	Charater->Artifact->AttachToComponent(PivotComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
	
	GetGameInstance()->GetSubsystem<UQuestSubsystem>()->CompleteQuest(this);
}

// Called every frame
void AEndgameAltar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

