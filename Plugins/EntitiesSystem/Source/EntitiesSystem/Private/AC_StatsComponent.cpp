// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_StatsComponent.h"

#include "PDA_StatsClass.h"


// Sets default values for this component's properties
UAC_StatsComponent::UAC_StatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UAC_StatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UAC_StatsComponent::InitializeStats(UPDA_StatsClass* NewBaseStats)
{
	BaseStats = NewBaseStats;

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UAC_StatsComponent::BindedFunction_OnTakeAnyDamage);

	ActualizeStats();
}

void UAC_StatsComponent::ActualizeStats()
{

	if (BaseStats)
	{
		Stats.Append(BaseStats->Stats);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player Base Stats In Stats Component"));
	}
}

void UAC_StatsComponent::BindedFunction_OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	AddStatValue(-Damage, EStatsTypes::HEALTH);

	UE_LOG(LogTemp, Warning, TEXT("Current Health: %f"), Stats.Find(EStatsTypes::HEALTH)->CurrentValue);
}

float UAC_StatsComponent::GetStatCurrentValue(EStatsTypes Stat)
{
	if (!Stats.Find(Stat)) return 0;
	return Stats.Find(Stat)->CurrentValue;
}

float UAC_StatsComponent::GetStatMaxValue(EStatsTypes Stat)
{
	if (!Stats.Find(Stat)) return 0;
	return Stats.Find(Stat)->MaxValue;
}








void UAC_StatsComponent::AddStatValue(float Value, EStatsTypes Stat)
{
	if (!Stats.Find(Stat)) return;

	Stats.Find(Stat)->CurrentValue = FMath::Clamp(Stats.Find(Stat)->CurrentValue + Value, 0, Stats.Find(Stat)->MaxValue);

	SetStatValue(Stats.Find(Stat)->CurrentValue, Stat);
}


void UAC_StatsComponent::SetStatValue(float Value, EStatsTypes Stat)
{
	if (!Stats.Find(Stat)) return;


	float OriginalValue = Stats.Find(Stat)->CurrentValue;
	Stats.Find(Stat)->CurrentValue = Value;

	OnStatValueChanged.Broadcast(Value / Stats.Find(Stat)->MaxValue, Stat);

	//Little Check For Health Because it's one of the most important stats
	if (Stat == EStatsTypes::HEALTH && Stats.Find(Stat)->CurrentValue <= 0 && OriginalValue != 0) OnDeath.Broadcast();
}







