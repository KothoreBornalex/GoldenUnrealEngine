// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_WeaponComponent.generated.h"

class UPDA_WeaponDataClass;
class UNiagaraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class WEAPONSSYSTEM_API UAC_WeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_WeaponComponent();

	void OnComponentCreated();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintImplementableEvent, Category = "Debug")
	void PrintEvent();


	UFUNCTION(BlueprintCallable)
	void SetUpComponent(UStaticMeshComponent* MeshComponent, UNiagaraComponent* VFXComponent, UPrimaryDataAsset* NewWeaponData);

	UFUNCTION(BlueprintCallable)
	void ShootByTracing();

	UFUNCTION()
	void ApplyDamage(AActor* Actor, float Damage);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsMagazineFull();



	UFUNCTION(BlueprintCallable)
	void ShootEffects();

public:
	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
	TObjectPtr<UStaticMeshComponent> WeaponMeshComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
	TObjectPtr<UNiagaraComponent> MuzzleFlashComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon|Data")
	TObjectPtr<UPDA_WeaponDataClass> WeaponData;


	UPROPERTY(BlueprintReadWrite, Category = "Weapon|Data")
	int AmmoInClip = 6;

};