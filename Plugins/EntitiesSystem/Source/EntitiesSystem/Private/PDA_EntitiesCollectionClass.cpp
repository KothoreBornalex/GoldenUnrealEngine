// Fill out your copyright notice in the Description page of Project Settings.


#include "PDA_EntitiesCollectionClass.h"

#include <PDA_EntityClass.h>

void UPDA_EntitiesCollectionClass::AddEntitiyToCollection()
{
	EntitiesCollection.Add(FName(FGuid::NewGuid().ToString()), nullptr);
}

void UPDA_EntitiesCollectionClass::BakeCollection()
{

    for (TPair<FName, TObjectPtr<UPDA_EntityClass>>& pair : EntitiesCollection) {

        if(IsValid(pair.Value))
        {
            if (pair.Value->EntityID != pair.Key)
            {
                if (EntitiesCollection.Find(pair.Value->EntityID))
                {
                    EntitiesCollection.Remove(pair.Key);
                }
                else
                {
                    pair.Key = pair.Value->EntityID;
                }
            }
        }else
        {
            EntitiesCollection.Remove(pair.Key);
        }
        
    }
    
}
