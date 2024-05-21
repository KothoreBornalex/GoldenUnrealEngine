// Fill out your copyright notice in the Description page of Project Settings.


#include "PropsActor.h"
#include "AC_StatsComponent.h"
#include <PDA_PropsClass.h>

// Sets default values
APropsActor::APropsActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetUpEvent_PhysicEntity.AddDynamic(this, &APropsActor::SetUpProps);

	StatsComponent = CreateDefaultSubobject<UAC_StatsComponent>("StatsComponent");

}

void APropsActor::SetUpProps()
{

	if (EntityData)
	{
		PropsData = Cast<UPDA_PropsClass>(EntityData);

		EntityMesh->SetStaticMesh(PropsData->PropsMesh);

		if(PropsData->IsPhysicSimulated)
		{
			NetUpdateFrequency = 30.0f;
			EntityMesh->SetSimulatePhysics(true);
			EntityMesh->SetEnableGravity(true);
			EntityMesh->SetMassOverrideInKg("nullptr", PropsData->Mass, true);
		}


		if(PropsData->Stats)
		{
			StatsComponent->BaseStats = PropsData->Stats;

			StatsComponent->InitializeStats();
			

		}else
		{
			UE_LOG(LogTemp, Warning, TEXT("No Stats in PDA_PropsData"));
		}
		
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Entity Data"));
	}

	SetUpEvent_PhysicEntity.RemoveDynamic(this, &APropsActor::SetUpProps);
}

// Called when the game starts or when spawned
void APropsActor::BeginPlay()
{
	Super::BeginPlay();

	EntityMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	EntityMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
}