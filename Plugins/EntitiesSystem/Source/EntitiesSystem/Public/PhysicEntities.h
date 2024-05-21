// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <F_ItemSlot.h>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicEntities.generated.h"

class UPDA_EntityClass;
class UPDA_EntitiesSubBankClass;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBaseEventDelegate);


UCLASS()
class ENTITIESSYSTEM_API APhysicEntities : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APhysicEntities();



	UFUNCTION(Server, Reliable)
	void Server_Reliable_SetUpPhysicEntity(F_ItemSlot NewItemSlot);

	UFUNCTION(NetMultiCast, Unreliable)
	void NetMulticast_Unreliable_SetUpPhysicEntity(F_ItemSlot NewItemSlot);


public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> EntityMesh;


	UPROPERTY()
	F_ItemSlot EntitySlot;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UPDA_EntityClass> EntityData;

	UPROPERTY(BlueprintAssignable)
	FBaseEventDelegate SetUpEvent_PhysicEntity;
};
