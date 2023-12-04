// Created by Nghia Lam <nghialam12795@gmail.com>. See LICENSE for more details

#include "PlayerCommon/PAPlayerController.h"

#include "Character/PACharacterPlayer.h"
#include "PlayerCommon/PAPlayerInput.h"
#include "ProceduralAnim/ProceduralAnimLog.h"

APAPlayerController::APAPlayerController()
{
}

void APAPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	PlayerCharacter = Cast<APACharacterPlayer>(GetCharacter());
	if (PlayerCharacter)
	{
		PlayerCharacter->GetPlayerInputComponent()->InitInput(InputComponent);
	}
	else
	{
		PALOG_WARNING("[APAPlayerController] This controller should be attached to a APACharacterPlayer character!");
	}
}
