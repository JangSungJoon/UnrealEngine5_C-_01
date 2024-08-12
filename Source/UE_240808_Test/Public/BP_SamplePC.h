// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BP_SamplePC.generated.h"

class UInputMappingContext;
class UInputAction;
class ABasePawn;
struct FInputActionValue;

UCLASS()
class UE_240808_TEST_API ABP_SamplePC : public APlayerController
{
	GENERATED_BODY()

private:
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PossessAction;

protected:
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* InPawn) override;

public:
	void Jump();
	void StopJumping();
	void DoPossess();
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FJumpDelegate);

	UPROPERTY(BlueprintAssignable)
	FJumpDelegate JumpDelegate;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	ABasePawn* PossessedBasePawn;

};
