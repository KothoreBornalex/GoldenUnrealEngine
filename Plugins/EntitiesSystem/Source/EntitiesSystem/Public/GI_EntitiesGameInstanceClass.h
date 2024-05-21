// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "F_ItemSlot.h"

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GI_EntitiesGameInstanceClass.generated.h"

class UPDA_EntityClass;
class UPDA_EntitiesBankClass;
class UPDA_ItemClass;
/**
 * 
 */
UCLASS()
class ENTITIESSYSTEM_API UGI_EntitiesGameInstanceClass : public UGameInstance
{
	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable, Category = "ESP|Entities")
	UPDA_ItemClass* GetItemData(F_ItemSlot ItemSlot);

	UFUNCTION(BlueprintCallable, Category = "ESP|Entities")
	UPDA_EntityClass* GetEntityData(F_ItemSlot ItemSlot);

	UFUNCTION(BlueprintCallable, Category = "ESP|Entities")
	F_ItemSlot GetEntityItemSlot(FName EntityID);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entities")
	TObjectPtr<UPDA_EntitiesBankClass> EntitiesBankRef;
};
