// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"
#include "Engine/World.h"
#include "WeaponBase.h"

ACharacterBase::ACharacterBase() {
	//charHealth = 100.0f;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	hasWeapon = false;
}

void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector newWeaponLocation = GetActorLocation();
	
	if (hasWeapon) {
		CurrentWeapon->SetActorLocation(GetActorLocation());
	}
}

void ACharacterBase::AttachWeapon() {
	hasWeapon = true;
	weaponTypeAttach = "Rifle";

	CurrentWeapon = GetWorld()->SpawnActor<AWeaponBase>(WeaponType, GetActorLocation(), GetActorRotation());

	CurrentWeapon->weaponType = weaponTypeAttach;
	
}