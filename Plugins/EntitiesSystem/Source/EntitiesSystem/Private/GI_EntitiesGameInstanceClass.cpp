// Fill out your copyright notice in the Description page of Project Settings.


#include "GI_EntitiesGameInstanceClass.h"

#include <PDA_EntitiesBankClass.h>
#include <PDA_ItemClass.h>
#include <PDA_EntitiesSubBankClass.h>

#include "PDA_EntitiesCollectionClass.h"
#include "PDA_PropsClass.h"


UPDA_ItemClass* UGI_EntitiesGameInstanceClass::GetItemData(F_ItemSlot ItemSlot)
{
	
    // Check if EntitiesBankRef is valid
    if (!EntitiesBankRef)
    {
        UE_LOG(LogTemp, Error, TEXT("EntitiesBankRef is nullptr"));
        return nullptr;
    }

    // Attempt to find EntitiesListClass for the given SubBankID
    UPDA_EntitiesSubBankClass* EntitiesSubBankAsset = EntitiesBankRef->EntitiesBank.FindRef(ItemSlot.SubBankID);
    if (!EntitiesSubBankAsset)
    {
        UE_LOG(LogTemp, Error, TEXT("EntitiesSubBank not found for SubBankID: %s"), *ItemSlot.SubBankID.ToString());
        return nullptr;
    }

    UPDA_EntitiesCollectionClass* EntitiesCollectionAsset = EntitiesSubBankAsset->EntitiesSubBank.FindRef(ItemSlot.CollectionID);
    if (!EntitiesCollectionAsset)
    {
        UE_LOG(LogTemp, Error, TEXT("EntitiesCollectionAsset not found for CollectionID: %s"), *ItemSlot.CollectionID.ToString());
        return nullptr;
    }


    // Attempt to find UPDA_EntityClass for the given EntityID within EntitiesSubBank
    UPDA_EntityClass* EntityClass = EntitiesCollectionAsset->EntitiesCollection.FindRef(ItemSlot.EntityID);
    if (!EntityClass)
    {
        UE_LOG(LogTemp, Error, TEXT("UPDA_EntityClass not found for EntityID: %s"), *ItemSlot.EntityID.ToString());
        return nullptr;
    }

    // Cast the UPDA_EntityClass to UPDA_ItemClass
    UPDA_ItemClass* ItemClass = Cast<UPDA_ItemClass>(EntityClass);
    if (!ItemClass)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to cast UPDA_EntityClass to UPDA_ItemClass"));
        return nullptr;
    }

    return ItemClass;
}


UPDA_EntityClass* UGI_EntitiesGameInstanceClass::GetEntityData(F_ItemSlot ItemSlot)
{

    // Check if EntitiesBankRef is valid
    if (!EntitiesBankRef)
    {
        UE_LOG(LogTemp, Error, TEXT("EntitiesBankRef is nullptr"));
        return nullptr;
    }

    // Attempt to find EntitiesListClass for the given SubBankID
    UPDA_EntitiesSubBankClass* EntitiesSubBankAsset = EntitiesBankRef->EntitiesBank.FindRef(ItemSlot.SubBankID);
    if (!EntitiesSubBankAsset)
    {
        UE_LOG(LogTemp, Error, TEXT("EntitiesSubBank not found for SubBankID: %s"), *ItemSlot.SubBankID.ToString());
        return nullptr;
    }

    UPDA_EntitiesCollectionClass* EntitiesCollectionAsset = EntitiesSubBankAsset->EntitiesSubBank.FindRef(ItemSlot.CollectionID);
    if (!EntitiesCollectionAsset)
    {
        UE_LOG(LogTemp, Error, TEXT("EntitiesCollectionAsset not found for CollectionID: %s"), *ItemSlot.CollectionID.ToString());
        return nullptr;
    }


    // Attempt to find UPDA_EntityClass for the given EntityID within EntitiesSubBank
    UPDA_EntityClass* EntityClass = EntitiesCollectionAsset->EntitiesCollection.FindRef(ItemSlot.EntityID);
    if (!EntityClass)
    {
        UE_LOG(LogTemp, Error, TEXT("UPDA_EntityClass not found for EntityID: %s"), *ItemSlot.EntityID.ToString());
        return nullptr;
    }


    return EntityClass;
}



F_ItemSlot UGI_EntitiesGameInstanceClass::GetEntityItemSlot(FName EntityID)
{
    if(!EntitiesBankRef)
    {
        UE_LOG(LogTemp, Warning, TEXT("Not Entities Bank"));
        return F_ItemSlot();
    }

    for (const TPair<FName, TObjectPtr<UPDA_EntitiesSubBankClass>>& SubBankPair : EntitiesBankRef->EntitiesBank)
    {
        if (SubBankPair.Value != nullptr)
        {
            UE_LOG(LogTemp, Warning, TEXT("Value Isn't NullPtr"))
        }else
        {
            UE_LOG(LogTemp, Warning, TEXT("Value Is NullPtr"))
        }


        for (const TPair<FName, TObjectPtr<UPDA_EntitiesCollectionClass>>& CollectionPair : SubBankPair.Value->EntitiesSubBank)
        {
            if (CollectionPair.Value != nullptr)
            {
                UE_LOG(LogTemp, Warning, TEXT("Value Isn't NullPtr"))
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Value Is NullPtr"))
            }


            if (CollectionPair.Value->EntitiesCollection.FindRef(EntityID) != nullptr)
            {
                F_ItemSlot value;
                value.ItemCount = 1;
                value.EntityID = EntityID;
                value.CollectionID = CollectionPair.Key;
                value.SubBankID = SubBankPair.Key;

                return value;
            }

        }
       
    }
    return F_ItemSlot();
}
