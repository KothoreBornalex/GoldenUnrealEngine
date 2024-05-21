// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "F_ItemSlot.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_EntitiesComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class ENTITIESSYSTEM_API UAC_EntitiesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_EntitiesComponent();

	UFUNCTION(BlueprintCallable, Category = "Entities|Management")
	void Interacting(APlayerController* PlayerInteracting);

	UFUNCTION(BlueprintCallable, Category = "Entities|Management")
	void SpawnEntity(F_ItemSlot EntitySlot, int Count);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


		
};
