// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "PhysicEntities.h"
#include "AmbianceSoundActor.generated.h"

/**
 * 
 */

class UAudioComponent;
class UPDA_AmbiantSoundClass;

UCLASS()
class ENTITIESSYSTEM_API AAmbianceSoundActor : public APhysicEntities, public IInteractInterface
{
	GENERATED_BODY()



public:
	AAmbianceSoundActor();

	UPROPERTY()
	TObjectPtr<UAudioComponent> AudioSource;

	UPROPERTY()
	bool IsPlaying;

	UPROPERTY()
	float AudioSourceRange;

	UPROPERTY()
	float AudioSourceVolume;

	UPROPERTY()
	TObjectPtr<UPDA_AmbiantSoundClass> SoundData;

	UFUNCTION()
	virtual void Interact_Implementation(APlayerController* playerInteracting) override;

	UFUNCTION(Server, Reliable)
	void Server_Reliable_CallPlayAudioSource();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_Reliable_PlayAudioSource();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_Reliable_StopPlayingAudioSource();

	UFUNCTION(BlueprintCallable)
	void SetAudioSourceVolume(float NewVolume);

	UFUNCTION(BlueprintCallable)
	void SetAudioSourceRange(float NewRange);



private:
	UFUNCTION()
	void SetUpAmbianceSoundActor();
};
