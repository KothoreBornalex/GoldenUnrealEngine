// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AC_EntitiesComponent.h"
#include "F_ItemSlot.h"
#include "Components/ActorComponent.h"
#include "Net/UnrealNetwork.h"

#include "AC_InventoryComponent.generated.h"


class UGI_EntitiesGameInstanceClass;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class ENTITIESSYSTEM_API UAC_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_InventoryComponent();

	void OnComponentCreated();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UAC_EntitiesComponent> EntitiesComponent;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UGI_EntitiesGameInstanceClass> EntitiesGameInstance;

	UPROPERTY(BlueprintReadOnly)
	TMap<FName, F_ItemSlot> Inventory;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TObjectPtr<AActor> CameraActor;




	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory|Management")
	void PrintEvent();



	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory|Management")
	void SpawnNotif(FName ItemName, bool Add);




	UFUNCTION(BlueprintCallable, Category = "Inventory|Management")
	void AddItem(F_ItemSlot ItemSlot);


	UFUNCTION(BlueprintCallable, Category = "Inventory|Management")
	void RemoveSingleItem(F_ItemSlot ItemSlot, bool SpawnItem);



	UFUNCTION(BlueprintCallable, Category = "Inventory|Management")
	void RemoveFullyItem(F_ItemSlot ItemSlot, bool SpawnItem);



	UFUNCTION(BlueprintCallable, Category = "Inventory|Management")
	void RemoveAmountItem(F_ItemSlot ItemSlot, bool SpawnItem, int Amount);

};
