// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "E_StatsTypes.h"
#include "F_Stat.h"
#include "Engine/DataAsset.h"
#include "PDA_StatsClass.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ENTITIESSYSTEM_API UPDA_StatsClass : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<EStatsTypes, F_Stat> Stats;
};
