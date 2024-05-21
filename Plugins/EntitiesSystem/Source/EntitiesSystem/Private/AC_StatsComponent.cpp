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

void UAC_StatsComponent::Server_Reliable_InitializeStats_Implementation()
{
	if(BaseStats)
	{
		Stats.Append(BaseStats->Stats);

		//Client_Reliable_InitializeStats();

	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Base Stats in Server Stats Component"));
	}
	
}

void UAC_StatsComponent::Client_Reliable_InitializeStats_Implementation()
{
	if (BaseStats)
	{
		Stats.Append(BaseStats->Stats);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Base Stats in Client Stats Component"));
	}
}

void UAC_StatsComponent::InitializeStats()
{
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UAC_StatsComponent::BindedFunction_OnTakeAnyDamage);

	if (BaseStats)
	{
		Stats.Append(BaseStats->Stats);

	}
	else
	{

	}
}



void UAC_StatsComponent::BindedFunction_OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	Server_Reliable_AddStatValue(-Damage, EStatsTypes::HEALTH);
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








void UAC_StatsComponent::Server_Reliable_AddStatValue_Implementation(float Value, EStatsTypes Stat)
{
	if (!Stats.Find(Stat)) return;

	Stats.Find(Stat)->CurrentValue = FMath::Clamp(Stats.Find(Stat)->CurrentValue + Value, 0, Stats.Find(Stat)->MaxValue);
	UE_LOG(LogTemp, Warning, TEXT("Current Health: %f"), Stats.Find(Stat)->CurrentValue);

	Client_Reliable_SetStatValue(Stats.Find(Stat)->CurrentValue, Stat);
}

void UAC_StatsComponent::Server_Reliable_SetStatValue_Implementation(float Value, EStatsTypes Stat)
{
	if (!Stats.Find(Stat)) return;

	Stats.Find(Stat)->CurrentValue = FMath::Clamp(Value, 0, Stats.Find(Stat)->MaxValue);

	Client_Reliable_SetStatValue(Stats.Find(Stat)->CurrentValue, Stat);
}


void UAC_StatsComponent::Client_Reliable_SetStatValue_Implementation(float Value, EStatsTypes Stat)
{
	if (!Stats.Find(Stat)) return;


	float OriginalValue = Stats.Find(Stat)->CurrentValue;
	Stats.Find(Stat)->CurrentValue = Value;

	OnStatValueChanged.Broadcast(Value / Stats.Find(Stat)->MaxValue, Stat);

	//Little Check For Health Because it's one of the most important stats
	if (Stat == EStatsTypes::HEALTH && Stats.Find(Stat)->CurrentValue <= 0 && OriginalValue != 0) OnDeath.Broadcast();
}







