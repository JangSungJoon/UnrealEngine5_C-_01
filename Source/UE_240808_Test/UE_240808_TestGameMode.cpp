// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_240808_TestGameMode.h"
#include "UE_240808_TestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_240808_TestGameMode::AUE_240808_TestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
