// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PDA_ItemClass.h"
#include "PDA_ItemConsummableClass.generated.h"

/**
 * 
 */
UCLASS()
class ENTITIESSYSTEM_API UPDA_ItemConsummableClass : public UPDA_ItemClass
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Consummable")
	float ConsumptionValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Consummable")
	FName RessourceEntityID;
};
