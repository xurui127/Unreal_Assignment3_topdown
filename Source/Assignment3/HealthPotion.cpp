// Fill out your copyright notice in the Description page of Project Settings.



#include "HealthPotion.h"
#include "Assignment3Character.h"

// Sets default values
AHealthPotion::AHealthPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHealthPotion::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHealthPotion::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AAssignment3Character* myCharacter = Cast<AAssignment3Character>(OtherActor);
	if (myCharacter != nullptr) {
		myCharacter->postion_Health += 1;
		Destroy();
	}
	GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("111111"));
}

// Called every frame
void AHealthPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

