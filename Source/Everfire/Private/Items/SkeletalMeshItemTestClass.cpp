// Copyright (C) 2024 Reavers & Marauders (R&M) Game Studios


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
