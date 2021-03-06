// Copyright Epic Games, Inc. All Rights Reserved.

#include "Assignment3PlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Assignment3Character.h"
#include "Engine/World.h"
#include "Math/Vector.h"

AAssignment3PlayerController::AAssignment3PlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AAssignment3PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void AAssignment3PlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AAssignment3PlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AAssignment3PlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AAssignment3PlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AAssignment3PlayerController::MoveToTouchLocation);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AAssignment3PlayerController::OnResetVR);
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AAssignment3PlayerController::OnShoot);
	InputComponent->BindAction("Attack", IE_Pressed, this, &AAssignment3PlayerController::OnAttack);
	InputComponent->BindAction("DrinkHealth", IE_Pressed, this, &AAssignment3PlayerController::DrinkHealth);
	InputComponent->BindAction("DrinkMana", IE_Pressed, this, &AAssignment3PlayerController::DrinkMana);
	InputComponent->BindAction("DrinkSpeed", IE_Pressed, this, &AAssignment3PlayerController::DrinkSpeed);
	InputComponent->BindAction("Roll", IE_Pressed, this, &AAssignment3PlayerController::Rolling);
	//InputComponent->BindAction("Spell", IE_Pressed, this, &AAssignment3PlayerController::AOESpell);
}

void AAssignment3PlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AAssignment3PlayerController::MoveToMouseCursor()
{
	
		if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
		{
			if (AAssignment3Character* MyPawn = Cast<AAssignment3Character>(GetPawn()))
			{
				if (MyPawn->GetCursorToWorld())
				{
					
					UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
				}
			}
		}
		else
		{
			
				
				//GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("move"));
				// Trace to see what is under the mouse cursor
				FHitResult Hit;
				GetHitResultUnderCursor(ECC_Visibility, false, Hit);

				if (Hit.bBlockingHit)
				{
					// We hit something, move there
					SetNewMoveDestination(Hit.ImpactPoint);
				}
			

			
			
		}
	
	
}

void AAssignment3PlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AAssignment3PlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	
		APawn* const MyPawn = GetPawn();
		if (MyPawn)
		{
			
		
				float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

				// We need to issue move command only if far enough in order for walk animation to play correctly
				if ((Distance > 120.0f))
				{
					UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
				}
		
			
		}
	
}

void AAssignment3PlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	
		bMoveToMouseCursor = true;
	
}

void AAssignment3PlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	
		bMoveToMouseCursor = false;
	
}

void AAssignment3PlayerController::OnShoot()
{	
	bool checkMP;
	AAssignment3Character* MyCharacter = Cast<AAssignment3Character>(GetPawn());

	
	checkMP = MyCharacter->CheckMP();
	if (checkMP) {
		GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("Pew"));
		

		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{


			FVector Dirction = Hit.ImpactPoint - MyCharacter->GetActorLocation();
			Dirction.Z = 0;
			MyCharacter->SetActorRotation(FRotationMatrix::MakeFromX(Dirction).Rotator());
		}

		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyCharacter->GetActorLocation());
		MyCharacter->Shoot();
	}
	else {
		GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("No Mana"));
	}
	
}

void AAssignment3PlayerController::OnAttack()
{
	
	
	AAssignment3Character* MyCharacter = Cast<AAssignment3Character>(GetPawn());
	
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit)
	{


		FVector Dirction = Hit.ImpactPoint - MyCharacter->GetActorLocation();
		Dirction.Z = 0;
		MyCharacter->SetActorRotation(FRotationMatrix::MakeFromX(Dirction).Rotator());
	}

	Cast<AAssignment3Character>(GetPawn())->Attack();

	//MyCharacter->Attack();
	
	//isAttack = true;


	
}
void AAssignment3PlayerController::DrinkHealth()
{
	Cast<AAssignment3Character>(GetPawn())->HealthDrink();
	//GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("Call HealthDrink"));
}
void AAssignment3PlayerController::DrinkMana()
{
	Cast<AAssignment3Character>(GetPawn())->ManaDrink();
	//GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("Call ManaDrink"));

}
void AAssignment3PlayerController::DrinkSpeed()
{
	Cast<AAssignment3Character>(GetPawn())->SpeedDrink();
}
void AAssignment3PlayerController::Rolling()
{
	Cast<AAssignment3Character>(GetPawn())->Rolling();
}
//
//void AAssignment3PlayerController::AOESpell()
//{
//
//	AAssignment3Character* MyCharacter = Cast<AAssignment3Character>(GetPawn());
//	
//
//
//	MyCharacter->Spell();
//
//}



