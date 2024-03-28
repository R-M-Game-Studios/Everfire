// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemBase.h"
#include "Components/SphereComponent.h"

// Sets default values
AItemBase::AItemBase() :
	ItemTag(TEXT("<ItemTag>")) // placeholder
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh")); //For weapons it might be wise to change to SkeletalMeshComponent
	SetRootComponent(ItemMesh);

	OverlapDetectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	OverlapDetectionSphere->SetupAttachment(RootComponent);
	OverlapDetectionSphere->SetSphereRadius(200.f);
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();

	// Setup overlap for the overlap detection sphere
	OverlapDetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::ItemBeginOverlap);
	OverlapDetectionSphere->OnComponentEndOverlap.AddDynamic(this, &AItemBase::ItemEndOverlap);
	
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemBase::ItemBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FString DebugMessage = FString::Printf(TEXT("Overlap Begins"));
	if(GEngine) GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, DebugMessage);
}

void AItemBase::ItemEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString DebugMessage = FString::Printf(TEXT("Overlap Ends"));
	if(GEngine) GEngine->AddOnScreenDebugMessage(2, 1.f, FColor::Green, DebugMessage);
}

