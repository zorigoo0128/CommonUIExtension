// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModularGameplayActors/GSCModularPlayerController.h"
#include "UObject/UObjectGlobals.h"

#include "CommonPlayerController.generated.h"

class APawn;
class UObject;

UCLASS(config=Game)
class COMMONUIEXTENSION_API ACommonPlayerController : public AGSCModularPlayerController
{
	GENERATED_BODY()

public:
	ACommonPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void ReceivedPlayer() override;	
	virtual void SetPawn(APawn* InPawn) override;
	virtual void OnPossess(class APawn* APawn) override;
	virtual void OnUnPossess() override;
	
protected:
	virtual void OnRep_PlayerState() override;
};
