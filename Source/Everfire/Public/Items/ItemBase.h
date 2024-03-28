// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/ObjectPtr.h"
#include "ItemBase.generated.h"

UCLASS()
class EVERFIRE_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	TObjectPtr<UMeshComponent> ItemMesh;

private:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Collision", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USphereComponent> OverlapDetectionSphere;
	
	/** The tag of the item to check what type of item it is, such as if it is a sword, a weapon
	 * with the corresponding sword will spawn on player inventory or equipped as a weapon component */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Information", meta = (AllowPrivateAccess = "true"))
	FName ItemTag;	

protected:
	UFUNCTION()
	virtual void ItemBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult & SweepResult);

	UFUNCTION()
	virtual void ItemEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
public:

	FORCEINLINE FName GetItemTag(){ return ItemTag; }	

};
