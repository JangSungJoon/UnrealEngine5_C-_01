// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_SamplePC.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "BasePawn.h"

void ABP_SamplePC::SetupInputComponent()
{
	Super::SetupInputComponent();

	JumpDelegate.AddDynamic(this, &ABP_SamplePC::Jump);
	StopJumpDelegate.AddDynamic(this, &ABP_SamplePC::StopJumping);

	if (UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		SubSystem->AddMappingContext(DefaultMappingContext, 0);
	}
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ABP_SamplePC::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ABP_SamplePC::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABP_SamplePC::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABP_SamplePC::Look);

		EnhancedInputComponent->BindAction(PossessAction, ETriggerEvent::Completed, this, &ABP_SamplePC::DoPossess);
	}
}

void ABP_SamplePC::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	JumpDelegate.Clear();
	StopJumpDelegate.Clear();

	/*if (ABasePawn* basepawn = Cast<ABasePawn>(InPawn))
	{
		PossessedBasePawn = basepawn;
	}
	else
	{
		PossessedBasePawn = nullptr;
	}*/
	PossessedBasePawn = Cast<ABasePawn>(InPawn);

	if (PossessedBasePawn)
	{
		JumpDelegate.AddDynamic(PossessedBasePawn, &ABasePawn::Jump);
		StopJumpDelegate.AddDynamic(PossessedBasePawn, &ABasePawn::StopJumping);
	}
}



void ABP_SamplePC::Jump()
{
	APawn* pawn = GetPawn();
	if (ABasePawn* thispawn = Cast<ABasePawn>(pawn))
	{
		JumpDelegate.Broadcast();
		//thispawn->Jump();
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Fail Jump"));
	}
}

void ABP_SamplePC::StopJumping()
{
	APawn* pawn = GetPawn();
	if (ABasePawn* thispawn = Cast<ABasePawn>(pawn))
	{
		UE_LOG(LogTemp, Log, TEXT("Stop Jump"));
		StopJumpDelegate.Broadcast();
		//thispawn->StopJumping();
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Fail Jump End"));
	}
}

void ABP_SamplePC::DoPossess()
{
	if (PossessedBasePawn && PossessedBasePawn->overlappingPawn)
	{
		Possess(PossessedBasePawn->overlappingPawn);
	}
}


void ABP_SamplePC::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	APawn* pawn = GetPawn();
	if (pawn)
	{
		pawn->AddMovementInput(ForwardDirection, MovementVector.Y);
		pawn->AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ABP_SamplePC::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

