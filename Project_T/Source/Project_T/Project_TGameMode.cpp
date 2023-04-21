// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project_TGameMode.h"
#include "Project_TCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject_TGameMode::AProject_TGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
