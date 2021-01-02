// Fill out your copyright notice in the Description page of Project Settings.

#include "Assignment3Character.h"
#include "SpeedPotion.h"

// Sets default values
ASpeedPotion::ASpeedPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASpeedPotion::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpeedPotion::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AAssignment3Character* myCharacter = Cast<AAssignment3Character>(OtherActor);
	if (myCharacter != nullptr) {
		myCharacter->potion_Speed += 1;
		Destroy();
	}
}

// Called every frame
void ASpeedPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

