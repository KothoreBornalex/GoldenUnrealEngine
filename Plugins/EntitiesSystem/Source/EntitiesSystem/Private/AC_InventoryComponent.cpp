// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_InventoryComponent.h"
#include <Net/UnrealNetwork.h>

#include "InteractInterface.h"
#include "PickUpItem.h"
#include "Kismet/GameplayStatics.h"
#include <GI_EntitiesGameInstanceClass.h>

#include "PDA_ItemClass.h"
#include "PDA_ItemConsummableClass.h"

// Sets default values for this component's properties
UAC_InventoryComponent::UAC_InventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//SetComponentTickInterval(1.0f);
}


void UAC_InventoryComponent::OnComponentCreated()
{
	Super::OnComponentCreated();

	// Set replication only if we're not running in the editor
	SetIsReplicated(true);
}


// Called when the game starts
void UAC_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	EntitiesGameInstance = Cast<UGI_EntitiesGameInstanceClass>(UGameplayStatics::GetGameInstance(GetWorld()));


	// ...
}






void UAC_InventoryComponent::AddItem(F_ItemSlot ItemSlot)
{
	if (ItemSlot.ItemCount <= 0) return;
	
	UE_LOG(LogTemp, Warning, TEXT("Server Add Item !!!!!!!!!!!!"));


	// If It's a consummable we're getting the ressource it contain
	if(EntitiesGameInstance->GetItemData(ItemSlot)->ItemType == EItemType::CONSUMMABLE)
	{
		UPDA_ItemConsummableClass* ConsummableItem = Cast<UPDA_ItemConsummableClass>(EntitiesGameInstance->GetItemData(ItemSlot));

		int SavedItemCount = ItemSlot.ItemCount;
		ItemSlot = EntitiesGameInstance->GetEntityItemSlot(ConsummableItem->RessourceEntityID);
		ItemSlot.ItemCount = (int)(ConsummableItem->ConsumptionValue * SavedItemCount);
	}


	if (Inventory.Find(ItemSlot.EntityID))
	{
		Inventory.Find(ItemSlot.EntityID)->ItemCount += ItemSlot.ItemCount;
	}
	else
	{
		Inventory.Add(ItemSlot.EntityID, ItemSlot);
	}

}



void UAC_InventoryComponent::RemoveSingleItem(F_ItemSlot ItemSlot, bool SpawnItem)
{
	if (!Inventory.Find(ItemSlot.EntityID)) return;

	if(SpawnItem)
	{
		EntitiesComponent->SpawnEntity(ItemSlot, 1);
	}
	

	if (Inventory.Find(ItemSlot.EntityID)->ItemCount > 1)
	{
		Inventory.Find(ItemSlot.EntityID)->ItemCount -= 1;
	}
	else if (Inventory.Find(ItemSlot.EntityID)->ItemCount == 1)
	{
		Inventory.Remove(ItemSlot.EntityID);
	}

}




void UAC_InventoryComponent::RemoveFullyItem(F_ItemSlot ItemSlot, bool SpawnItem)
{
	if (!Inventory.Find(ItemSlot.EntityID)) return;
	
	if (SpawnItem)
	{
		EntitiesComponent->SpawnEntity(ItemSlot, Inventory.Find(ItemSlot.EntityID)->ItemCount);
	}

	Inventory.Remove(ItemSlot.EntityID);

}



void UAC_InventoryComponent::RemoveAmountItem(F_ItemSlot ItemSlot, bool SpawnItem, int Amount)
{
	if (!Inventory.Find(ItemSlot.EntityID)) return;

	int ClampedAmount = FMath::Clamp(Amount, 0, Inventory.Find(ItemSlot.EntityID)->ItemCount);

	
	if (SpawnItem)
	{
		EntitiesComponent->SpawnEntity(ItemSlot, ClampedAmount);
	}


	int NewAmount = Inventory.Find(ItemSlot.EntityID)->ItemCount - ClampedAmount;

	if(NewAmount > 0)
	{
		Inventory.Find(ItemSlot.EntityID)->ItemCount = NewAmount;
	}else
	{
		Inventory.Remove(ItemSlot.EntityID);
	}

}

