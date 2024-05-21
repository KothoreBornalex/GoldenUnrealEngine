// Fill out your copyright notice in the Description page of Project Settings.


#include "PDA_AmbiantSoundClass.h"

#include "AmbianceSoundActor.h"

UPDA_AmbiantSoundClass::UPDA_AmbiantSoundClass()
{
	PhysicEntityActorClass = AAmbianceSoundActor::StaticClass();
}
