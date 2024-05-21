// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "PDA_EntityClass.h"
#include "PDA_StatsClass.h"
#include "PDA_PropsClass.generated.h"

/**
 * 
 */
UCLASS()
class ENTITIESSYSTEM_API UPDA_PropsClass : public UPDA_EntityClass
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "ESP|Props")
	TObjectPtr<UStaticMesh> PropsMesh;

	UPROPERTY(EditAnywhere, Category = "ESP|Props")
	TObjectPtr<UPDA_StatsClass> Stats;

	UPROPERTY(EditAnywhere, Category = "ESP|Props")
	bool IsDestroyable;

	UPROPERTY(EditAnywhere, Category = "ESP|Props")
	bool IsPhysicSimulated;

	UPROPERTY(EditAnywhere, Category = "ESP|Props")
	float Mass;
};
