// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EverfirePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class EVERFIRE_API AEverfirePlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AEverfirePlayerController();

protected:

	virtual void BeginPlay() override;
	
};
