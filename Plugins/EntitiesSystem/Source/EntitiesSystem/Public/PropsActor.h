// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicEntities.h"
#include "GameFramework/Actor.h"
#include "PropsActor.generated.h"

class UAC_StatsComponent;
class UPDA_PropsClass;

UCLASS()
class ENTITIESSYSTEM_API APropsActor : public APhysicEntities
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APropsActor();

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAC_StatsComponent> StatsComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UPDA_PropsClass> PropsData;


private:

	UFUNCTION()
	void SetUpProps();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
