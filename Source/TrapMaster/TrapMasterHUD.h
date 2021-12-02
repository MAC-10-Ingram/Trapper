// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TrapMasterHUD.generated.h"

UCLASS()
class ATrapMasterHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATrapMasterHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

