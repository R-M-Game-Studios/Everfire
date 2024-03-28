// Copyright (C) 2024 Reavers & Marauders (R&M) Game Studios

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
