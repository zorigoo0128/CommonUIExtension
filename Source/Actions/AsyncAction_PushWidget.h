// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Delegates/Delegate.h"
#include "Engine/CancellableAsyncAction.h"
#include "GameplayTagContainer.h"
#include "Templates/SharedPointer.h"
#include "UObject/SoftObjectPtr.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/WeakObjectPtrTemplates.h"

#include "AsyncAction_PushWidget.generated.h"

class APlayerController;
class UCommonActivatableWidget;
class UObject;
struct FFrame;
struct FStreamableHandle;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPushWidgetAsyncDelegate, UCommonActivatableWidget*, UserWidget);

/**
 * 
 */
UCLASS(BlueprintType)
class COMMONUIEXTENSION_API UAsyncAction_PushWidget : public UCancellableAsyncAction
{
	GENERATED_UCLASS_BODY()

public:
	virtual void Cancel() override;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext = "WorldContextObject", BlueprintInternalUseOnly="true"))
	static UAsyncAction_PushWidget* PushWidgetToLayer(APlayerController* OwningPlayer, UPARAM(meta = (AllowAbstract=false)) TSoftClassPtr<UCommonActivatableWidget> WidgetClass, UPARAM(meta = (Categories = "UI.Layer")) FGameplayTag LayerName, bool bSuspendInputUntilComplete = true);

	virtual void Activate() override;

public:

	UPROPERTY(BlueprintAssignable)
	FPushWidgetAsyncDelegate BeforePush;

	UPROPERTY(BlueprintAssignable)
	FPushWidgetAsyncDelegate AfterPush;

private:

	FGameplayTag LayerName;
	bool bSuspendInputUntilComplete = false;
	TWeakObjectPtr<APlayerController> OwningPlayerPtr;
	TSoftClassPtr<UCommonActivatableWidget> WidgetClass;

	TSharedPtr<FStreamableHandle> StreamingHandle;
};
