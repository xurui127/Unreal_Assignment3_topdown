// Copyright Epic Games, Inc. All Rights Reserved.

#include "Assignment3GameMode.h"
#include "Assignment3PlayerController.h"
#include "Assignment3Character.h"
#include "UObject/ConstructorHelpers.h"

AAssignment3GameMode::AAssignment3GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAssignment3PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}