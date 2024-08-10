// Copyright Epic Games, Inc. All Rights Reserved.

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

/**
 * Implements the FCommonUIExtensionModule module.
 */
class FCommonUIExtensionModule : public IModuleInterface
{
public:
	FCommonUIExtensionModule();
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:

};


FCommonUIExtensionModule::FCommonUIExtensionModule()
{
}

void FCommonUIExtensionModule::StartupModule()
{
}

void FCommonUIExtensionModule::ShutdownModule()
{
}

IMPLEMENT_MODULE(FCommonUIExtensionModule, CommonUIExtension);
