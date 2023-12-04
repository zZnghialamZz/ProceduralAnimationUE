// Created by Nghia Lam <nghialam12795@gmail.com>. See LICENSE for more details

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "InputActionValue.h"
#include "PlayerMappableInputConfig.h"
#include "Components/ActorComponent.h"
#include "PAPlayerInput.generated.h"

class APACharacterPlayer;

USTRUCT()
struct FMappableConfig
{
	GENERATED_BODY()

	FMappableConfig() = default;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UPlayerMappableInputConfig> Config;

	/**
	 * The type of config that this is. Useful for filtering out configs by the current input device
	 * for things like the settings screen, or if you only want to apply this config when a certain
	 * input type is being used.
	 */
	UPROPERTY(EditAnywhere)
	ECommonInputType Type = ECommonInputType::Count;

	/**
	 * If true, then this input config will be activated when it's associated Game Feature is activated.
	 * This is normally the desirable behavior
	 */
	UPROPERTY(EditAnywhere)
	bool bShouldActivateAutomatically = true;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROCEDURALANIM_API UPAPlayerInput : public UActorComponent
{
	GENERATED_BODY()

public:
	UPAPlayerInput();

	void InitInput(UInputComponent* PlayerInputComponent);
	void RequestMove(const FInputActionValue& Value);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "PlayerInput")
	TArray<FMappableConfig> DefaultInputConfigs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerInput|Actions")
	TObjectPtr<UInputAction> MoveInputAction;

private:
	UPROPERTY(VisibleAnywhere, Category = "Player")
	TObjectPtr<APACharacterPlayer> PlayerCharacter;
};
