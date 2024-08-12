// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));

	jumpMultiplier = 100.f;
}

void ABasePawn::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (APawn* pawn = Cast<APawn>(OtherActor))
	{
		overlappingPawn = pawn;
	}
	
	Super::NotifyActorBeginOverlap(OtherActor);
}

void ABasePawn::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (overlappingPawn == OtherActor)
	{
		overlappingPawn = nullptr;
	}

	Super::NotifyActorEndOverlap(OtherActor);
}

void ABasePawn::BeginOverlap(AActor* OtherActor)
{
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasePawn::Jump()
{
	AddActorLocalOffset(GetActorUpVector() * jumpMultiplier);
}

void ABasePawn::StopJumping()
{
	AddActorLocalOffset(GetActorUpVector() * -jumpMultiplier);
}

