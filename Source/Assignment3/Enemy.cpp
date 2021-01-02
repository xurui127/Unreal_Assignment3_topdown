// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Assignment3Character.h"
#include "Assignment3PlayerController.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Player shoot Enemy

void AEnemy::OnHit()
{
	if (countTimer==false) {
		HitValue = 1;

		HP -= 20;
	}
	else
	{
		HitValue = 1;

		HP -= 50;
	}

}

// Player Attack Enemy
void AEnemy::PunchHit()
{
	HitValue = 1;
	
		HP -= 20;
		furyAdd = true;
}

void AEnemy::AOEHit()
{
	HitValue = 1;
	HP -= 5;


}



// Enemy get Player ultimate resource Hit
void AEnemy::DoubleHit()
{
	HitValue = 1;
	HP -= 100;



	
}

void AEnemy::AttackPlayer(AAssignment3Character* myPlayer,bool roll)
{
	if (roll == false) {
		myPlayer->HP -= 20;

	}


}




//FVector AEnemy::GetEnemyLocation()
//{
//	enemyLocation = this->Getpawn();
//	return enemyLocation;
//}




//
//void AEnemy::PlayAttack(FVector playerLocation,FVector enemyLocation)
//{
//	if (playerLocation.Size() - enemyLocation.Size()<=1000.0f) {
//		PlayAnimMontage(EnemyAttack);
//	}
//}

void AEnemy::PlayAnimAttact()
{
	PlayAnimMontage(EnemyAttack);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AAssignment3Character*	myPlayer = Cast<AAssignment3Character>(player);

	//AttackPlayer(myPlayer,myPlayer->isRoll);
	//Enemy Attack 

	//PlayAttack(myPlayer->GetActorLocation(),this->GetActorLocation());
	// Player Get Experience And LEVEL UP
	if (myPlayer != nullptr) {
		if (HP <= 0) {
			isDeath = true;
			Destroy();
			
		}
		if (isDeath == true) {
			isDeath = false;
			myPlayer->experience += 50;
			if (myPlayer->experience >= myPlayer->playerExe) {
				myPlayer->experience = 0;
				myPlayer->playerExe += 40;
				myPlayer->level += 1;
				
			}
		}
		// Gain Player Fury 
		if (furyAdd == true) {
			furyAdd = false;
			myPlayer->fury += 20;
			if (myPlayer->fury>=100) {
				
				countTimer = true;
			
				
				
				//countTimer = false;
			}
			
			
		}
		if (countTimer == true) {
			furyTimer -= DeltaTime;
			if (furyTimer <= 0) {
				myPlayer->fury = 0;
				countTimer = false;

			}
		}
	
	}


	HitValue -= DeltaTime;
	if (HitValue < 0) {
		HitValue = 0;
	}

	SkeletalMesh->SetScalarParameterValueOnMaterials(TEXT("Hit"), HitValue);
	

}


// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

