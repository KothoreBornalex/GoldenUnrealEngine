// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "PropsActor.h"
#include "PropsInteractibleActor.generated.h"

/**
 * 
 */
UCLASS()
class ENTITIESSYSTEM_API APropsInteractibleActor : public APropsActor, public IInteractInterface
{
	GENERATED_BODY()
public:
	APropsInteractibleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintType)
	virtual void Interact_Implementation(APlayerController* playerInteracting) override;
};
