// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_SampleActor_1.h"

// Sets default values
ABP_SampleActor_1::ABP_SampleActor_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FirstTickCalled = false;
}

// Called when the game starts or when spawned
void ABP_SampleActor_1::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABP_SampleActor_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	if (FirstTickCalled == false)
	{
		FirstTickCalled = true;
		InitialX = GetActorLocation().X;
	}

	float TargetX;
	float NegativeX;
	//float WaytoGoX;
	//float WaytoGoNegative;


	TargetX = CurrentLocation.X + Multiplier;
	NegativeX = CurrentLocation.X - Multiplier;


	if (IsPositive1000)
	{
		SetActorLocation(FVector(TargetX, CurrentLocation.Y, CurrentLocation.Z));
		//WaytoGoX = CurrentLocation.X + AbsoluteX;
		if (TargetX >= 1000.0f)
		{
			IsPositive1000 = false;
		}
	}
	else
	{
		SetActorLocation(FVector(NegativeX, CurrentLocation.Y, CurrentLocation.Z));
		//WaytoGoNegative = CurrentLocation.X - AbsoluteX;
		if (NegativeX <= -1000.0f)
		{
			IsPositive1000 = true;
		}
	}




}

