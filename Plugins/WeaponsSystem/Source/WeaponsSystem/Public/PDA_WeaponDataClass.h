// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NiagaraFunctionLibrary.h"

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PDA_WeaponDataClass.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONSSYSTEM_API UPDA_WeaponDataClass : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Visual")
	TObjectPtr<USkeletalMesh> WeaponSkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Visual")
	TObjectPtr<UNiagaraSystem> MuzzleFlashEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Audio")
	TArray<TObjectPtr<USoundBase>> ShootSounds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Visual")
	TObjectPtr<UMaterialInterface> BulletHoleMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Data")
	FName AmmoItemID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Settings")
	bool IsAuto = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Stats")
	int ClipSize = 32;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Stats")
	float ReloadTime = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Stats")
	float Damage = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Stats")
	float FireRate = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Stats")
	float FireRange = 10000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Stats")
	float Spread = 2.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon|Settings")
	FName MuzzleSocketName = "Socket_Muzzle";
};
