// Created by Nghia Lam <nghialam12795@gmail.com>. See LICENSE for more details

#include "Character/PACharacterBase.h"

APACharacterBase::APACharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void APACharacterBase::MoveCharacter(const FVector2D& MovementVector)
{
}
