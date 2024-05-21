// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PDA_ItemEquippableClass.h"
#include "PDA_ItemWeaponClass.generated.h"

/**
 * 
 */
UCLASS()
class ENTITIESSYSTEM_API UPDA_ItemWeaponClass : public UPDA_ItemEquippableClass
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Weapon")
	TObjectPtr<UPrimaryDataAsset> WeaponData;
};
