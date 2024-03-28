// Fill out your copyright notice in the Description page of Project Settings.


#include "NonHumanoids/NonHumanoidBase.h"

// Sets default values
ANonHumanoidBase::ANonHumanoidBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANonHumanoidBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANonHumanoidBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANonHumanoidBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

