// Fill out your copyright notice in the Description page of Project Settings.

#include "Assignment3Character.h"
#include "LootBox.h"

// Sets default values
ALootBox::ALootBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}



void ALootBox::SpawnHealthPotion(FVector charloc, FRotator charrot)
{

	FActorSpawnParameters SpawnParams;
	AActor* SpawnHealthRef = GetWorld()->SpawnActor<AActor>(SpawnHealth, charloc, charrot, SpawnParams);
}

void ALootBox::SpawnManaPotion(FVector charloc, FRotator charrot)
{
	FActorSpawnParameters SpawnParams;
	AActor* SpawnManaRef = GetWorld()->SpawnActor<AActor>(SpawnMana, charloc, charrot, SpawnParams);
}

void ALootBox::SpawnSpeedPotion(FVector charloc, FRotator charrot)
{
	FActorSpawnParameters SpawnParams;
	AActor* SpawnSpeedRef = GetWorld()->SpawnActor<AActor>(SpawnSpeed, charloc, charrot, SpawnParams);
}

// Called when the game starts or when spawned
void ALootBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALootBox::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AAssignment3Character* myCharacter = Cast<AAssignment3Character>(OtherActor);
	if (myCharacter != nullptr) {
		
		randomNum = FMath::RandRange(1, 100);

		if (randomNum >= 0 && randomNum <= 60) {
		
			float ranNum = FMath::RandRange(100, 500);
			FVector ranLoc = GetActorLocation() + ranNum;
			ranLoc.Z = 0;
			FVector spawnLocation = GetActorLocation() + ranLoc;
			FRotator spawnRotation(0.0f, 0.0f, 0.0f);

			SpawnHealthPotion(spawnLocation, spawnRotation);
			GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("11111111"));

		}
		if (randomNum >= 61 && randomNum <=90 ) {

			float ranNum = FMath::RandRange(100, 500);
			FVector ranLoc = GetActorLocation() + ranNum;
			ranLoc.Z = 0;
			FVector spawnLocation = GetActorLocation() + ranLoc;
			FRotator spawnRotation(0.0f, 0.0f, 0.0f);

			SpawnManaPotion(spawnLocation, spawnRotation);
			GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("2222222"));

		}
		if (randomNum >= 91 && randomNum <= 100) {

			float ranNum = FMath::RandRange(100, 500);
			FVector ranLoc = GetActorLocation() + ranNum;
			ranLoc.Z = 0;
			FVector spawnLocation = GetActorLocation() + ranLoc;
			FRotator spawnRotation(0.0f, 0.0f, 0.0f);

			SpawnSpeedPotion(spawnLocation, spawnRotation);
			GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("33333333"));

		}
		Destroy();


	}
}

// Called every frame
void ALootBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

