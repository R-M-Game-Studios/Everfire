// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EverfireGameMode.generated.h"

/**
 * 
 */
UCLASS()
class EVERFIRE_API AEverfireGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	AEverfireGameMode();

protected:

	virtual void BeginPlay() override;
	
};
