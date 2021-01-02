// Fill out your copyright notice in the Description page of Project Settings.

#include "ManaPotion.h"
#include "Assignment3Character.h"

// Sets default values
AManaPotion::AManaPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AManaPotion::BeginPlay()
{
	Super::BeginPlay();
	
}

void AManaPotion::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AAssignment3Character* myCharacter = Cast<AAssignment3Character>(OtherActor);
	if (myCharacter != nullptr) {
		myCharacter->potion_Mana += 1;
		Destroy();
	}
	//GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("222222"));
}

// Called every frame
void AManaPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

