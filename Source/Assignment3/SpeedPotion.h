// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpeedPotion.generated.h"

UCLASS()
class ASSIGNMENT3_API ASpeedPotion : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpeedPotion();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor)override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
