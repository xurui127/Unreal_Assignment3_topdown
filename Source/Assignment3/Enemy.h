// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Assignment3Character.h"
#include "Enemy.generated.h"



UCLASS()
class ASSIGNMENT3_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();
	
	UPROPERTY(BlueprintReadOnly)
	int HP=100;

	UPROPERTY(BlueprintReadWrite)
	USkeletalMeshComponent* SkeletalMesh;

	float HitValue;

	UFUNCTION(BlueprintCallable)
		void OnHit();
	UFUNCTION(BlueprintCallable)
		void PunchHit();

	UFUNCTION(BlueprintCallable)
		void AOEHit();
	
	bool isDeath;
	
	UFUNCTION(BlueprintCallable)
		void DoubleHit();
	float doubleHitTimer=5.0f;
	
	bool doubleHit;

	UFUNCTION(BlueprintCallable)
		void AttackPlayer(AAssignment3Character* myPlayer,  bool roll);

	ACharacter* player;
	

	bool furyAdd;

	float furyTimer=10.0f;
	bool countTimer;
	 // FVector GetEnemyLocation();


	/*UFUNCTION(BlueprintCallable)
		void PlayAttack(FVector playerLocation, FVector enemyLocation);
		*/
	UPROPERTY(EditAnywhere)
		UAnimMontage* EnemyAttack;

	UFUNCTION(BlueprintCallable)
	void PlayAnimAttact();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
