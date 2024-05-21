// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "F_Stat.generated.h"

USTRUCT(BlueprintType)
struct ENTITIESSYSTEM_API F_Stat
{
public:
	GENERATED_BODY()

	F_Stat();
	~F_Stat();


public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CurrentValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxValue;

};
