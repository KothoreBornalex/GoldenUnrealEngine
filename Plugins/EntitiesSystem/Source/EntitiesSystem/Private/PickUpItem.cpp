// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpItem.h"

#include <PDA_ItemClass.h>
#include "AC_InventoryComponent.h"

// Sets default values
APickUpItem::APickUpItem()
{
	PrimaryActorTick.bCanEverTick = false;

	SetUpEvent_PhysicEntity.AddDynamic(this, &APickUpItem::SetUpItem);

	NetUpdateFrequency = 15.0f;
}

void APickUpItem::Interact_Implementation(APlayerController* playerInteracting)
{
	UAC_InventoryComponent* InventoryComponent = playerInteracting->GetPawn()->FindComponentByClass<UAC_InventoryComponent>();

	if(InventoryComponent)
	{
		InventoryComponent->AddItem(EntitySlot);
		Destroy();
	}

	
}

void APickUpItem::SetUpItem()
{
	if(EntityData)
	{
		ItemData = Cast<UPDA_ItemClass>(EntityData);

		EntityMesh->SetStaticMesh(ItemData->ItemDroppedMesh);
	}

	SetUpEvent_PhysicEntity.RemoveDynamic(this, &APickUpItem::SetUpItem);
}

// Called when the game starts or when spawned
void APickUpItem::BeginPlay()
{
	Super::BeginPlay();

	EntityMesh->SetSimulatePhysics(true);
	EntityMesh->SetEnableGravity(true);
	EntityMesh->SetMassOverrideInKg("nullptr", 10.0f, true);
	EntityMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	EntityMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
}