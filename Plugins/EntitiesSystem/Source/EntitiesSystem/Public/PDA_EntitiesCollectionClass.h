// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PDA_EntitiesCollectionClass.generated.h"

class UPDA_EntityClass;

UCLASS()
class ENTITIESSYSTEM_API UPDA_EntitiesCollectionClass : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, CallInEditor)
	void AddEntitiyToCollection();

	UFUNCTION(BlueprintCallable, CallInEditor)
	void BakeCollection();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entities")
	FName CollectionName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entities")
	TMap<FName, TObjectPtr<UPDA_EntityClass>> EntitiesCollection;
};
