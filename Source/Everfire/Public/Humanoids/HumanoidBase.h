// Copyright (C) 2024 Reavers & Marauders (R&M) Game Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UObject/ObjectPtr.h"
#include "HumanoidBase.generated.h"

UCLASS()
class EVERFIRE_API AHumanoidBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHumanoidBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	/** Spring Arm to attach the camera too, adjusts the distance from the object with the arm length */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> SpringArmComponent;

private:
	
	/** Camera that is attached to the spring arm */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> HumanoidCameraComponent;

	

};
