// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "F_ItemSlot.generated.h"

USTRUCT(BlueprintType)
struct ENTITIESSYSTEM_API F_ItemSlot
{
public:
	GENERATED_BODY()

	F_ItemSlot();
	~F_ItemSlot();


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|LookUpTable")
	FName SubBankID;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|LookUpTable")
	FName CollectionID;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|LookUpTable")
	FName EntityID;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|Stats")
	int ItemCount;
};
