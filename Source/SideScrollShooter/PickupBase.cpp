// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupBase.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APickupBase::APickupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	RootComponent = SphereComp;
	
}

void APickupBase::NotifyActorBeginOverlap(AActor * OtherActor)
{
	OnActivate(OtherActor);
}

void APickupBase::PickedUp(AActor * PickedUpBy)
{
	ASpawner* spawner = (ASpawner*)GetOwner();
	if (GetOwner() != NULL)

	{
		spawner->RespawnBegin();
	}

	Destroy();
}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

