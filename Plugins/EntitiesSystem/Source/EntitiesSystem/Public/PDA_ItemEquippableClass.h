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





	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Equippable|Camera")
	float CameraAnimationStrength = 35.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Equippable|Camera")
	float WeaponSwaySmoothness = 13.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Equippable|Camera")
	float WeaponSwayForce = 1.7f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Equippable|Camera")
	float WalkRotationAnimationForce = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Equippable|Camera")
	float WalkPositionAnimationForce = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Equippable|Camera")
	float CoyoteTime = 0.35f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ESP|Item|Equippable|ShortRangeAtack")
	float ShortRangeAttack_Cooldown = 3.0f;
};
