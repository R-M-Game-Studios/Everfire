// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/SkeletalMeshItemTestClass.h"

ASkeletalMeshItemTestClass::ASkeletalMeshItemTestClass()
{
	ItemMesh->DestroyComponent();
	ItemMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ItemSkeletalMesh"));
	SetRootComponent(ItemMesh);
}

void ASkeletalMeshItemTestClass::BeginPlay()
{
	Super::BeginPlay();
}

void ASkeletalMeshItemTestClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
