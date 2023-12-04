// Created by Nghia Lam <nghialam12795@gmail.com>. See LICENSE for more details

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PAPlayerController.generated.h"

class APACharacterPlayer;

UCLASS()
class PROCEDURALANIM_API APAPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APAPlayerController();

protected:
	virtual void OnPossess(APawn* InPawn) override;

private:
	TObjectPtr<APACharacterPlayer> PlayerCharacter;
};
