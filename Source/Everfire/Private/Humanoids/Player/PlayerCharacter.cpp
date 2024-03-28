// Fill out your copyright notice in the Description page of Project Settings.


#include "Humanoids/Player/PlayerCharacter.h"

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


APlayerCharacter::APlayerCharacter() :
	// EnhancedInput-related variables
	PlayerMappingContext(nullptr),
	MovementAction(nullptr),
	LookAction(nullptr),
	JumpAction(nullptr),
	/* PRIVATE VARIABLES BELOW */
	// Variables for Look-function
	LookRate(45.f),
	bInvertPitchAxis(false)
{
	SpringArmComponent->TargetArmLength = 0.f;
	SpringArmComponent->SocketOffset = FVector(20.f, 0.f, 45.f);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if(const APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PlayerMappingContext, 0);
		}
	}
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Jump);
	}
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	if(GetWorld() && GetMovementComponent() && GetController())
	{
		const float MovementSpeed = GetMovementComponent()->GetMaxSpeed();
       	const FVector2D MovementVector = Value.Get<FVector2D>() * GetWorld()->GetDeltaSeconds() * MovementSpeed;
       
       	const FRotator Rotation = GetController()->GetControlRotation();
       	const FRotator YawRotation = FRotator(0.f, Rotation.Yaw, 0.f);
       
       	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
       	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
       
       	AddMovementInput(ForwardDirection, MovementVector.Y);
       	AddMovementInput(RightDirection, MovementVector.X);	
	}
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
	if(GetWorld())
	{
		const FVector2D LookAxisVector = Value.Get<FVector2D>() * GetWorld()->GetDeltaSeconds() * LookRate;

		if(bInvertPitchAxis) AddControllerPitchInput(-LookAxisVector.Y);
		else AddControllerPitchInput(LookAxisVector.Y);

		AddControllerYawInput(LookAxisVector.X);
	}	
}

void APlayerCharacter::Jump()
{
	Super::Jump();
}
