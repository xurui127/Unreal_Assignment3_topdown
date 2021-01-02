// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpeedPotion.h"
#include "ManaPotion.h"
#include "HealthPotion.h"
#include "LootBox.generated.h"

UCLASS()
class ASSIGNMENT3_API ALootBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALootBox();

	//ASpeedPotion();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AActor> SpawnHealth;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AActor> SpawnMana;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AActor> SpawnSpeed;
	
	int randomNum;

	void SpawnHealthPotion(FVector charloc, FRotator charrot);
	void SpawnManaPotion(FVector charloc, FRotator charrot);
	void SpawnSpeedPotion(FVector charloc, FRotator charrot);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor)override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
