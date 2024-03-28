// Copyright (C) 2024 Reavers & Marauders (R&M) Game Studios

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
