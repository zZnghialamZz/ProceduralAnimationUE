// Created by Nghia Lam <nghialam12795@gmail.com>. See LICENSE for more details

#include "PlayerCommon/PAPlayerInput.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Character/PACharacterPlayer.h"
#include "ProceduralAnim/ProceduralAnimLog.h"

UPAPlayerInput::UPAPlayerInput()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPAPlayerInput::BeginPlay()
{
	Super::BeginPlay();
}

void UPAPlayerInput::InitInput(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	if (!PlayerCharacter)
	{
		PlayerCharacter = CastChecked<APACharacterPlayer>(GetOwner());
		if (!PlayerCharacter)
		{
			PALOG_ERROR("[UPAPlayerInput] This component should be attached to an APACharacterPlayer character!")
			return;
		}
	}

	const APlayerController* PC = PlayerCharacter->GetController<APlayerController>();
	check(PC);

	const ULocalPlayer* LP = PC->GetLocalPlayer();
	check(LP);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	// Register any default input configs
	for (const FMappableConfig& InputConfig : DefaultInputConfigs)
	{
		if (InputConfig.bShouldActivateAutomatically)
		{
			FModifyContextOptions Options = {};
			Options.bIgnoreAllPressedKeysUntilRelease = false;

			Subsystem->AddPlayerMappableConfig(InputConfig.Config.LoadSynchronous(), Options);
		}
	}

	// Bind Actions
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &UPAPlayerInput::RequestMove);
}

void UPAPlayerInput::RequestMove(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	if (PlayerCharacter)
	{
		PlayerCharacter->MoveCharacter(MovementVector);
	}
}
