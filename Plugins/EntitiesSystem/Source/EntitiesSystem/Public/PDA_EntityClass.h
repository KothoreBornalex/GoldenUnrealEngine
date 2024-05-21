// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RenderResource.h"
#include <E_Entities.h>

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PDA_EntityClass.generated.h"


/**
 * 
 */
UCLASS()
class ENTITIESSYSTEM_API UPDA_EntityClass : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entity")
	FName EntityID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entity")
	EEntityType EntityType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entity")
	TObjectPtr<UClass> PhysicEntityActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entity")
	TObjectPtr<UTexture2D> EntityThumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Entity")
	FText EntityDescription;
};
