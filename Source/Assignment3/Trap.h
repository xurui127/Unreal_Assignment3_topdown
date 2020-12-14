// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "Trap.generated.h"

UCLASS()
class ASSIGNMENT3_API ATrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrap();
	
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;
	
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AEnemy> SpawnEnemy;


	void EnemySpawn(FVector charloc, FRotator charrot);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor)override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
