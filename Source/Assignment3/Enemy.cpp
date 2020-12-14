// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Assignment3Character.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Player shoot Enemy

void AEnemy::OnHit()
{
	HitValue = 1;

	HP -= 20;
	isDeath();
}

// Player Attack Enemy
void AEnemy::PunchHit()
{
	HitValue = 1;
	HP -= 10;
	isDeath();
}

void AEnemy::AOEHit()
{
	HitValue = 1;
	HP -= 5;
	isDeath();
}

bool AEnemy::isDeath()
{
	if (HP <= 0)
	{
		Destroy();
		return true;
	}
	else {
		return false;
	}

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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

