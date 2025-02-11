// Copyright (C) 2024 Reavers & Marauders (R&M) Game Studios

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase.h"
#include "SkeletalMeshItemTestClass.generated.h"

/**
 * 
 */
UCLASS()
class EVERFIRE_API ASkeletalMeshItemTestClass : public AItemBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASkeletalMeshItemTestClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
