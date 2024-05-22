// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <E_StatsTypes.h>
#include "F_Stat.h"
#include "AC_StatsComponent.generated.h"


class UPDA_StatsClass;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeathDelegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStatReachZeroDelegate, const EStatsTypes&, StatType);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStatValueChanged, float, StatValuePercentage, const EStatsTypes&, StatType);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class ENTITIESSYSTEM_API UAC_StatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_StatsComponent();

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UPDA_StatsClass> BaseStats;

	UPROPERTY(BlueprintAssignable)
	FDeathDelegate OnDeath;

	UPROPERTY(BlueprintAssignable)
	FStatReachZeroDelegate OnStatReachZero;

	UPROPERTY(BlueprintAssignable)
	FStatValueChanged OnStatValueChanged;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	UPROPERTY()
	TMap<EStatsTypes, F_Stat> Stats;


public:
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void InitializeStats(UPDA_StatsClass* NewBaseStats);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ActualizeStats();

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void BindedFunction_OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);


	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetStatValue(float Value, EStatsTypes Stat);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void AddStatValue(float Value, EStatsTypes Stat);




	UFUNCTION(BlueprintCallable, Category = "Stats")
	float GetStatCurrentValue(EStatsTypes Stat);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	float GetStatMaxValue(EStatsTypes Stat);
};
