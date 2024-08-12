// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_SampleActor_1.generated.h"

UCLASS()
class UE_240808_TEST_API ABP_SampleActor_1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABP_SampleActor_1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<USceneComponent> DefaultSceneRoot;
	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UStaticMeshComponent> SM_SampleMesh;
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	bool IsPositive1000;
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	FVector InitialLocation;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	double InitialX;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	double Multiplier;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	double AbsoluteX;

private:
	bool FirstTickCalled = false;

};
