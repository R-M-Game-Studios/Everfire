// Fill out your copyright notice in the Description page of Project Settings.

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
