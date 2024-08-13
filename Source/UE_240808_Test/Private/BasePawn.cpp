// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "BP_SamplePC.h"

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

void ABasePawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (ABP_SamplePC* MyPC = Cast<ABP_SamplePC>(NewController))
	{
		MyPC->JumpDelegate.AddDynamic(this, &ABasePawn::Jump);
		MyPC->StopJumpDelegate.AddDynamic(this, &ABasePawn::StopJumping);
	}
}

void ABasePawn::UnPossessed()
{
	GetController();
	if (ABP_SamplePC* MyPC = Cast<ABP_SamplePC>(GetController()))
	{
		MyPC->JumpDelegate.Clear();
		MyPC->StopJumpDelegate.Clear();
	}
	Super::UnPossessed();
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

