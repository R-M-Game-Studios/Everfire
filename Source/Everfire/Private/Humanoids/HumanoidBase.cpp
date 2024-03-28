// Copyright (C) 2024 Reavers & Marauders (R&M) Game Studios


#include "Humanoids/HumanoidBase.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AHumanoidBase::AHumanoidBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SocketOffset = FVector(0.f, 0.f, 70.f);

	HumanoidCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	HumanoidCameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	HumanoidCameraComponent->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void AHumanoidBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHumanoidBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHumanoidBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

