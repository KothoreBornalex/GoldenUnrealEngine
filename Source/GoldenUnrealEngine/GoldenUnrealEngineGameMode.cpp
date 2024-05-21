// Copyright Epic Games, Inc. All Rights Reserved.

#include "GoldenUnrealEngineGameMode.h"
#include "GoldenUnrealEngineCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGoldenUnrealEngineGameMode::AGoldenUnrealEngineGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
