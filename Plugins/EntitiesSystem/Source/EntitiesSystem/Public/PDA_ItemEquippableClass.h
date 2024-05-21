// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "EAnimationsOverlayType.h"
#include "PDA_ItemClass.h"
#include <EEquippableAnimMontages.h>

#include "PDA_ItemEquippableClass.generated.h"

/**
 * 
 */
UCLASS()
class ENTITIESSYSTEM_API UPDA_ItemEquippableClass : public UPDA_ItemClass
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "ALS|Item|Equippable")
	UAnimMontage* GetEquippableAnimMontage(EEquippableAnimMontages EquippableAnimInstance);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Equippable")
	EAnimationsOverlayType AnimationsOverlayState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Equippable")
	TMap<EEquippableAnimMontages, TObjectPtr<UAnimMontage>> AnimMontagesMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Equippable")
	TObjectPtr<UClass> EquippableActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Equippable")
	FVector LocationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Equippable")
	FRotator RotationOffset;
};
