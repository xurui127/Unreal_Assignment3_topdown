// Fill out your copyright notice in the Description page of Project Settings.

#include "Assignment3Character.h"
#include "Enemy.h"
#include "Trap.h"

// Sets default values
ATrap::ATrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

void ATrap::EnemySpawn(FVector charloc,FRotator charrot)
{	
	
	FActorSpawnParameters SpawnParams;
	AEnemy* SpawnEnemyRef = GetWorld()->SpawnActor<AEnemy>(SpawnEnemy, charloc, charrot, SpawnParams);
}

// Called when the game starts or when spawned
void ATrap::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATrap::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AAssignment3Character* myCharacter = Cast<AAssignment3Character>(OtherActor);
	AEnemy* myEnmey = Cast<AEnemy>(OtherActor);
	if (myCharacter!=nullptr)
	{
		for(int i=0; i<3;i++){
		float ranNum = FMath::RandRange(100, 500);
		FVector ranLoc = GetActorLocation() + ranNum;
		ranLoc.Z = 0;
		FVector spawnLocation = GetActorLocation() + ranLoc;
		FRotator spawnRotation(0.0f, 0.0f, 0.0f);
		
		EnemySpawn(spawnLocation, spawnRotation);
		
		}
		Destroy();
	}
}

// Called every frame
void ATrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

