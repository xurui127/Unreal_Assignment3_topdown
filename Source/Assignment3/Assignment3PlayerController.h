// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Assignment3PlayerController.generated.h"


UCLASS()
class AAssignment3PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAssignment3PlayerController();

	//Player Evasive Movement Skill
	bool isRoll;
	//FVector distance;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	
	// Shoot projectile
	void OnShoot();

	// Player Atteck 
	bool isAttack;
	void OnAttack();

	//Player AOE Spell
	//void AOESpell();

	//Player Drink Posions
	void DrinkHealth();
	void DrinkMana();
	void DrinkSpeed();


	void Rolling();

};


