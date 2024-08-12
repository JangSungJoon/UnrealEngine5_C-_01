// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "MyPawn.generated.h"

class UBoxComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class UE_240808_TEST_API AMyPawn : public ABasePawn
{
	GENERATED_BODY()
	
	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> OverlapCollision;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> Camera;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> SpringArm;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> StaticMesh;

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AddGameScore();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int gamescore;
};
