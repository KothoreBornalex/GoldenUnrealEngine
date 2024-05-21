// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "E_Entities.h"

#include "PDA_EntitiesSubBankClass.generated.h"

class UPDA_EntityClass;
class UPDA_EntitiesCollectionClass;

UCLASS()
class ENTITIESSYSTEM_API UPDA_EntitiesSubBankClass : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entities")
	FName SubBankName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entities")
	EEntityType SubBankType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entities")
	TMap<FName, TObjectPtr<UPDA_EntitiesCollectionClass>> EntitiesSubBank;
};