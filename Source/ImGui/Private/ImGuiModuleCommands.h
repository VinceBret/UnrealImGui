// Distributed under the MIT License (MIT) (see accompanying LICENSE file)

#pragma once

#include <HAL/IConsoleManager.h>


struct FImGuiKeyInfo;
class FImGuiModuleProperties;

// Manges ImGui module console commands.
class FImGuiModuleCommands
{
public:

	static const TCHAR* const ToggleImGui;
	static const TCHAR* const ToggleKeyboardNavigation;
	static const TCHAR* const ToggleGamepadNavigation;
	static const TCHAR* const ToggleKeyboardInputSharing;
	static const TCHAR* const ToggleGamepadInputSharing;

	FImGuiModuleCommands(FImGuiModuleProperties& InProperties);

	void SetKeyBinding(const TCHAR* CommandName, const FImGuiKeyInfo& KeyInfo);

private:

	void ToggleImGuiImpl();
	void ToggleKeyboardNavigationImpl();
	void ToggleGamepadNavigationImpl();
	void ToggleKeyboardInputSharingImpl();
	void ToggleGamepadInputSharingImpl();
	
	FImGuiModuleProperties& Properties;

	FAutoConsoleCommand ToggleImGuiCommand;
	FAutoConsoleCommand ToggleKeyboardNavigationCommand;
	FAutoConsoleCommand ToggleGamepadNavigationCommand;
	FAutoConsoleCommand ToggleKeyboardInputSharingCommand;
	FAutoConsoleCommand ToggleGamepadInputSharingCommand;
};
