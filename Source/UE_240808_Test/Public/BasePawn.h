// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

class UFloatingPawnMovement;

UCLASS()
class UE_240808_TEST_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UFloatingPawnMovement> FloatingPawnMovement;
public:
	// Sets default values for this pawn's properties
	ABasePawn();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	virtual void BeginOverlap(AActor* OtherActor);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float jumpMultiplier;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APawn* overlappingPawn;

	void Jump();

	void StopJumping();
};
