// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPoolerSubsystem.h"
#include "ObjectPoolInterface.h"

void UObjectPoolerSubsystem::AddPool(TSubclassOf<AActor> ClassToPool, int32 InitialSize, AActor* Parent)
{
	UWorld* CurrentWorld = GetWorld();
	
	if (!IsValid(CurrentWorld)) return;
	if (!IsValid(ClassToPool)) return;
	if (!ClassToPool->ImplementsInterface(UObjectPoolInterface::StaticClass())) return;
	
	
	FObjectPool TempPool;
	const FActorSpawnParameters SpawnParameters;
	
	
	for (int32 i = 0; i < InitialSize; i++)
	{
		AActor* ActorRef = CurrentWorld->SpawnActor<AActor>(
			ClassToPool,
			FVector(0, 0, 100),
			FRotator(0, 0, 0),
			SpawnParameters
		);

		TempPool.UsablePoolingObjects.AddUnique(ActorRef);
		ActorRef->SetActorTickEnabled(false);
	}
		
	ObjectPoolMap.Add(ClassToPool, TempPool);
	
}

TScriptInterface<IObjectPoolInterface> UObjectPoolerSubsystem::GetObjectFromPool(TSubclassOf<AActor> ClassToPool)
{
	TScriptInterface<IObjectPoolInterface> Actor = nullptr;
	UWorld* CurrentWorld = GetWorld();
	
	if (!IsValid(CurrentWorld)) return Actor;
	if (!IsValid(ClassToPool)) return Actor;
	if (!ObjectPoolMap.Contains(ClassToPool)) return Actor;
	
	FObjectPool* PoolObject = ObjectPoolMap.Find(ClassToPool);

	if (!PoolObject) return Actor;
	
	if (PoolObject->UsablePoolingObjects.IsEmpty())
	{
		Actor = CurrentWorld->SpawnActor<AActor>(ClassToPool);
	}
	else
	{
		Actor = PoolObject->UsablePoolingObjects[0];
		PoolObject->UsablePoolingObjects.RemoveAt(0);
	}

	PoolObject->ActivePoolingObjects.AddUnique(Actor);
	return Actor;
}

void UObjectPoolerSubsystem::ReturnObjectToPool(TSubclassOf<AActor> ClassToPool, TScriptInterface<IObjectPoolInterface> ActorToReturn)
{
	if (!IsValid(ClassToPool)) return;
	if (!ObjectPoolMap.Contains(ClassToPool)) return;

	FObjectPool* PoolObject = ObjectPoolMap.Find(ClassToPool);

	if (!PoolObject->ActivePoolingObjects.Contains(ActorToReturn))
	{
		UE_LOG(LogTemp, Warning, TEXT("non è attivo"))
	}
	else
	{
		PoolObject->ActivePoolingObjects.Remove(ActorToReturn);
		PoolObject->UsablePoolingObjects.AddUnique(ActorToReturn);
	}
}

int UObjectPoolerSubsystem::GetUsablePoolSize(TSubclassOf<AActor> ClassToPool)
{
	if (!GetWorld()) return -1;
	if (!ObjectPoolMap.Contains(ClassToPool)) return -1;

	FObjectPool* PoolObject = ObjectPoolMap.Find(ClassToPool);

	return PoolObject->UsablePoolingObjects.Num();
}

int UObjectPoolerSubsystem::GetActivePoolSize(TSubclassOf<AActor> ClassToPool)
{
	if (!ObjectPoolMap.Contains(ClassToPool)) return -1;

	FObjectPool* PoolObject = ObjectPoolMap.Find(ClassToPool);

	return PoolObject->ActivePoolingObjects.Num();
}
