// Created by Nghia Lam <nghialam12795@gmail.com>. See LICENSE for more details

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PACharacterBase.generated.h"

UCLASS()
class PROCEDURALANIM_API APACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	APACharacterBase();
	
	UFUNCTION(BlueprintCallable, Category = "PACharacter|Actions")
	void MoveCharacter(const FVector2D& MovementVector);

protected:
	virtual void BeginPlay() override;
};
