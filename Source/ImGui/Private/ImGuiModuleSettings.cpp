// Distributed under the MIT License (MIT) (see accompanying LICENSE file)

#include "ImGuiPrivatePCH.h"

#include "ImGuiModuleSettings.h"

#include "ImGuiModuleCommands.h"
#include "ImGuiModuleProperties.h"


//====================================================================================================
// UImGuiSettings
//====================================================================================================

UImGuiSettings* UImGuiSettings::DefaultInstance = nullptr;

FSimpleMulticastDelegate UImGuiSettings::OnSettingsLoaded;

void UImGuiSettings::PostInitProperties()
{
	Super::PostInitProperties();

	if (IsTemplate())
	{
		DefaultInstance = this;
		OnSettingsLoaded.Broadcast();
	}
}

void UImGuiSettings::BeginDestroy()
{
	Super::BeginDestroy();

	if (DefaultInstance == this)
	{
		DefaultInstance = nullptr;
	}
}

//====================================================================================================
// FImGuiModuleSettings
//====================================================================================================

FImGuiModuleSettings::FImGuiModuleSettings(FImGuiModuleProperties& InProperties, FImGuiModuleCommands& InCommands)
	: Properties(InProperties)
	, Commands(InCommands)
{
#if WITH_EDITOR
	FCoreUObjectDelegates::OnObjectPropertyChanged.AddRaw(this, &FImGuiModuleSettings::OnPropertyChanged);
#endif

	// Delegate initializer to support settings loaded after this object creation (in stand-alone builds) and potential
	// reloading of settings.
	UImGuiSettings::OnSettingsLoaded.AddRaw(this, &FImGuiModuleSettings::UpdateSettings);

	// Call initializer to support settings already loaded (editor).
	UpdateSettings();
}

FImGuiModuleSettings::~FImGuiModuleSettings()
{

	UImGuiSettings::OnSettingsLoaded.RemoveAll(this);

#if WITH_EDITOR
	FCoreUObjectDelegates::OnObjectPropertyChanged.RemoveAll(this);
#endif
}

void FImGuiModuleSettings::UpdateSettings()
{
	if (UImGuiSettings* SettingsObject = UImGuiSettings::Get())
	{
		SetImGuiInputHandlerClass(SettingsObject->ImGuiInputHandlerClass);
		SetShareKeyboardInput(SettingsObject->bShareKeyboardInput);
		SetShareGamepadInput(SettingsObject->bShareGamepadInput);
		SetUseSoftwareCursor(SettingsObject->bUseSoftwareCursor);
		SetToggleImGuiKey(SettingsObject->ToggleImGui);
		SetToggleImGuiByDefault(SettingsObject->bToggleImGuiByDefault);
	}
}

void FImGuiModuleSettings::SetImGuiInputHandlerClass(const FStringClassReference& ClassReference)
{
	if (ImGuiInputHandlerClass != ClassReference)
	{
		ImGuiInputHandlerClass = ClassReference;
		OnImGuiInputHandlerClassChanged.Broadcast(ClassReference);
	}
}

void FImGuiModuleSettings::SetShareKeyboardInput(bool bShare)
{
	if (bShareKeyboardInput != bShare)
	{
		bShareKeyboardInput = bShare;
		Properties.SetKeyboardInputShared(bShare);
	}
}

void FImGuiModuleSettings::SetShareGamepadInput(bool bShare)
{
	if (bShareGamepadInput != bShare)
	{
		bShareGamepadInput = bShare;
		Properties.SetGamepadInputShared(bShare);
	}
}

void FImGuiModuleSettings::SetUseSoftwareCursor(bool bUse)
{
	if (bUseSoftwareCursor != bUse)
	{
		bUseSoftwareCursor = bUse;
		OnUseSoftwareCursorChanged.Broadcast(bUse);
	}
}

void FImGuiModuleSettings::SetToggleImGuiKey(const FImGuiKeyInfo& KeyInfo)
{
	if (ToggleImGuiKey != KeyInfo)
	{
		ToggleImGuiKey = KeyInfo;
		Commands.SetKeyBinding(FImGuiModuleCommands::ToggleImGui, ToggleImGuiKey);
	}
}

void FImGuiModuleSettings::SetToggleImGuiByDefault(bool bShare)
{
	bToogleImGuiByDefault = bShare;
	Properties.SetImGuiEnabled(bToogleImGuiByDefault);
}

#if WITH_EDITOR

void FImGuiModuleSettings::OnPropertyChanged(class UObject* ObjectBeingModified, struct FPropertyChangedEvent& PropertyChangedEvent)
{
	if (ObjectBeingModified == UImGuiSettings::Get())
	{
		UpdateSettings();
	}
}

#endif // WITH_EDITOR
