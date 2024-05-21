// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicEntities.h"

#include <GI_EntitiesGameInstanceClass.h>
#include <Kismet/GameplayStatics.h>
#include <PDA_ItemClass.h>


#include "AC_InventoryComponent.h"

// Sets default values
APhysicEntities::APhysicEntities()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	NetUpdateFrequency = 1.0f;

	EntityMesh = CreateDefaultSubobject<UStaticMeshComponent>("EntityMesh");

	SetRootComponent(EntityMesh);
}


// Called when the game starts or when spawned
void APhysicEntities::BeginPlay()
{
	Super::BeginPlay();

	SetReplicateMovement(true);
}



void APhysicEntities::Server_Reliable_SetUpPhysicEntity_Implementation(F_ItemSlot NewItemSlot)
{
	EntitySlot = NewItemSlot;
	TObjectPtr<UGI_EntitiesGameInstanceClass> EntitiesGameInstance = Cast<UGI_EntitiesGameInstanceClass>(UGameplayStatics::GetGameInstance(GetWorld()));
	EntityData = EntitiesGameInstance->GetEntityData(EntitySlot);

	NetMulticast_Unreliable_SetUpPhysicEntity(NewItemSlot);

	SetUpEvent_PhysicEntity.Broadcast();
}


void APhysicEntities::NetMulticast_Unreliable_SetUpPhysicEntity_Implementation(F_ItemSlot NewItemSlot)
{
	EntitySlot = NewItemSlot;
	TObjectPtr<UGI_EntitiesGameInstanceClass> EntitiesGameInstance = Cast<UGI_EntitiesGameInstanceClass>(UGameplayStatics::GetGameInstance(GetWorld()));
	EntityData = EntitiesGameInstance->GetEntityData(EntitySlot);

	SetUpEvent_PhysicEntity.Broadcast();
}