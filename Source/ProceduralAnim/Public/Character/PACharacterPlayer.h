// Created by Nghia Lam <nghialam12795@gmail.com>. See LICENSE for more details

#pragma once

#include "CoreMinimal.h"
#include "PACharacterBase.h"
#include "PACharacterPlayer.generated.h"

class UPAPlayerInput;

UCLASS()
class PROCEDURALANIM_API APACharacterPlayer : public APACharacterBase
{
	GENERATED_BODY()

public:
	APACharacterPlayer();
	
	UFUNCTION(BlueprintCallable, Category = "PACharacter|Component")
	UPAPlayerInput* GetPlayerInputComponent() const { return PlayerInput; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PACharacter|Component")
	TObjectPtr<UPAPlayerInput> PlayerInput;
};
