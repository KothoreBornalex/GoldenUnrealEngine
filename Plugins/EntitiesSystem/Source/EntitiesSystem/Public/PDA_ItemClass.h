// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <E_Items.h>

#include "CoreMinimal.h"
#include "PDA_EntityClass.h"
#include "PDA_ItemClass.generated.h"

/**
 * 
 */
UCLASS()
class ENTITIESSYSTEM_API UPDA_ItemClass : public UPDA_EntityClass
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item")
	int SellCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item")
	TObjectPtr<UStaticMesh> ItemDroppedMesh;
};
