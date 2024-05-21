// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "GameFramework/Actor.h"
#include "PhysicEntities.h"

#include "PickUpItem.generated.h"


class UPDA_ItemClass;

UCLASS()
class ENTITIESSYSTEM_API APickUpItem : public APhysicEntities, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpItem();

	UFUNCTION()
	virtual void Interact_Implementation(APlayerController* playerInteracting) override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UPDA_ItemClass> ItemData;

private:
	UFUNCTION()
	void SetUpItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
