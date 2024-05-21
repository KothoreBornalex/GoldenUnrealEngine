// Fill out your copyright notice in the Description page of Project Settings.


#include "EntityZoneEffect.h"

#include <Components/BoxComponent.h>

#include "Kismet/GameplayStatics.h"


AEntityZoneEffect::AEntityZoneEffect()
{
	PrimaryActorTick.bCanEverTick = false;
	ZoneTrigger = CreateDefaultSubobject<UBoxComponent>("ZoneTrigger");
}


void AEntityZoneEffect::BeginPlay()
{
	Super::BeginPlay();
	ZoneTrigger->OnComponentBeginOverlap.AddDynamic(this, &AEntityZoneEffect::OnBeginOverlap);
	ZoneTrigger->OnComponentEndOverlap.AddDynamic(this, &AEntityZoneEffect::OnEndOverlap);
}



void AEntityZoneEffect::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ActorsInsideZone.Num() == 0)
	{
		GetWorldTimerManager().SetTimer(DamageTimer, this, &AEntityZoneEffect::DealDamage, DamageInterval, true);
	}


	if (ActorsInsideZone.Find(OtherActor))
	{
		return;
	}
	else
	{
		ActorsInsideZone.Add(OtherActor);
	}

	//UE_LOG(LogTemp, Warning, TEXT("Overlap actor"));
}

void AEntityZoneEffect::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ActorsInsideZone.Remove(OtherActor);

	if(ActorsInsideZone.Num() == 0)
	{
		GetWorldTimerManager().ClearTimer(DamageTimer);
	}


	//UE_LOG(LogTemp, Warning, TEXT("Clear timer"));
}

void AEntityZoneEffect::DealDamage()
{
	for (auto& Elem : ActorsInsideZone)
	{

		if(Elem != nullptr)
		{
			UGameplayStatics::ApplyDamage(Elem, DamageValue, GetInstigatorController(), this, nullptr);
			//UE_LOG(LogTemp, Warning, TEXT("ATTTTAACCCKKK"));
		}
	}
}