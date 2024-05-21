// Fill out your copyright notice in the Description page of Project Settings.


#include "AmbianceSoundActor.h"
#include "Components/AudioComponent.h" 
#include "PDA_AmbiantSoundClass.h"
#include "PickUpItem.h"

// Sets default values
AAmbianceSoundActor::AAmbianceSoundActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetUpEvent_PhysicEntity.AddDynamic(this, &AAmbianceSoundActor::SetUpAmbianceSoundActor);

	AudioSource = CreateDefaultSubobject<UAudioComponent>("AudioSource");

	EntityMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	EntityMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
}

void AAmbianceSoundActor::Interact_Implementation(APlayerController* playerInteracting)
{
	Server_Reliable_CallPlayAudioSource();
}

void AAmbianceSoundActor::Server_Reliable_CallPlayAudioSource_Implementation()
{
	if(IsPlaying)
	{
		Multicast_Reliable_StopPlayingAudioSource();
		IsPlaying = false;
	}else
	{
		Multicast_Reliable_PlayAudioSource();
		IsPlaying = true;
	}
}

void AAmbianceSoundActor::Multicast_Reliable_PlayAudioSource_Implementation()
{
	AudioSource->SetSound(SoundData->Sound);
	AudioSource->Play();
}

void AAmbianceSoundActor::Multicast_Reliable_StopPlayingAudioSource_Implementation()
{
	AudioSource->Stop();
}




void AAmbianceSoundActor::SetAudioSourceVolume(float NewVolume)
{
	AudioSourceVolume = NewVolume;
	AudioSource->AdjustVolume(1.0f, AudioSourceVolume, EAudioFaderCurve::Logarithmic);
}

void AAmbianceSoundActor::SetAudioSourceRange(float NewRange)
{
	AudioSourceRange = NewRange;

	FSoundAttenuationSettings Settings = FSoundAttenuationSettings();
	
	AudioSource->AdjustAttenuation(Settings);
}


void AAmbianceSoundActor::SetUpAmbianceSoundActor()
{
	if (EntityData)
	{
		SoundData = Cast<UPDA_AmbiantSoundClass>(EntityData);
		AudioSource->AttenuationSettings = SoundData->SoundAttenuationSettings;

		EntityMesh->SetStaticMesh(SoundData->SoundActorMesh);
	}

	SetUpEvent_PhysicEntity.RemoveDynamic(this, &AAmbianceSoundActor::SetUpAmbianceSoundActor);
}
