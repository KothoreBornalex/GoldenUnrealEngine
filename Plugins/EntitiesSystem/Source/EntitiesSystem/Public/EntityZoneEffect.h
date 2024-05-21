// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EntityZoneEffect.generated.h"


class UBoxComponent;

UCLASS()
class ENTITIESSYSTEM_API AEntityZoneEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEntityZoneEffect();

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void DealDamage();


public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> ZoneTrigger;

	UPROPERTY(EditAnywhere)
	float DamageInterval = 1.0f;

	UPROPERTY(EditAnywhere)
	float DamageValue = 10.f;

	UPROPERTY()
	TSet<TObjectPtr<AActor>> ActorsInsideZone;

	FTimerHandle DamageTimer;

	
};
