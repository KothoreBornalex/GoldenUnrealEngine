// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PDA_EntitiesBankClass.generated.h"

class UPDA_EntitiesSubBankClass;
/**
 * 
 */
UCLASS()
class ENTITIESSYSTEM_API UPDA_EntitiesBankClass : public UPrimaryDataAsset
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entities")
	FName BankName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entities")
	TMap<FName, TObjectPtr<UPDA_EntitiesSubBankClass>> EntitiesBank;
};