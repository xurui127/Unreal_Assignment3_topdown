// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/ReflectionCaptureComponent.h"
#include "Assignment3/Enemy.h"
#include "Assignment3Character.generated.h"








UCLASS(Blueprintable)
class AAssignment3Character : public ACharacter
{
	GENERATED_BODY()

public:
	AAssignment3Character();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	UPROPERTY(BluePrintReadOnly)
	int HP=100;	
	UPROPERTY(BluePrintReadOnly)
	int MP=100 ;

	UPROPERTY(visibleAnywhere)
	USceneComponent* projectileOrigin;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor>ProjectileActor;

	

	//UPROPERTY(EditAnywhere,BluePrintReadWrite)
		//UAnimMontage* AM_Attack;

	void Shoot();


	bool CheckMP();

	//bool IsAttack;
	
	// Player  Call Attack 
	UFUNCTION(BlueprintImplementableEvent)
	void Attack();

	// gey character loction
	UPROPERTY(BlueprintReadOnly)
		FVector playerLocation;
	UPROPERTY(BlueprintReadOnly)
		FVector enemyLocation;


	FVector distance;
	float calDistance;

	//Player AOE Spell

	bool isClose;
	//UFUNCTION(BlueprintImplementableEvent)
	//void Spell();
	
	//virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;
};

