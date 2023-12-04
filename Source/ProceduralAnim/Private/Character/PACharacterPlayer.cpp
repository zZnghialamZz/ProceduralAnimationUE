// Created by Nghia Lam <nghialam12795@gmail.com>. See LICENSE for more details

#include "Character/PACharacterPlayer.h"

#include "PlayerCommon/PAPlayerInput.h"

APACharacterPlayer::APACharacterPlayer()
{
	PrimaryActorTick.bCanEverTick = false;
	
	// Setup components
	PlayerInput = CreateDefaultSubobject<UPAPlayerInput>(TEXT("Player Input"));
}

void APACharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
}
