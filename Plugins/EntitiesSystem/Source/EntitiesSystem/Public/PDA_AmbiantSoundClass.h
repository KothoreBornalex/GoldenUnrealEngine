// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PDA_EntityClass.h"
#include "PDA_AmbiantSoundClass.generated.h"

/**
 * 
 */
UCLASS()
class ENTITIESSYSTEM_API UPDA_AmbiantSoundClass : public UPDA_EntityClass
{
	GENERATED_BODY()


public:
	UPDA_AmbiantSoundClass();

	UPROPERTY(EditAnywhere, Category = "Audio");
	TObjectPtr<USoundBase> Sound;

	UPROPERTY(EditAnywhere, Category = "Audio");
	TObjectPtr<USoundAttenuation> SoundAttenuationSettings;

	UPROPERTY(EditAnywhere, Category = "Visual")
	TObjectPtr<UStaticMesh> SoundActorMesh;
};
