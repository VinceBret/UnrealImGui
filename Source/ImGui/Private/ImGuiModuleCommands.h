// Distributed under the MIT License (MIT) (see accompanying LICENSE file)

#pragma once

#include <HAL/IConsoleManager.h>


struct FImGuiKeyInfo;
class FImGuiModuleProperties;

// Manges ImGui module console commands.
class FImGuiModuleCommands
{
public:

	static const TCHAR* const ToggleInput;
	static const TCHAR* const ToggleImGui;
	static const TCHAR* const ToggleKeyboardNavigation;
	static const TCHAR* const ToggleGamepadNavigation;
	static const TCHAR* const ToggleKeyboardInputSharing;
	static const TCHAR* const ToggleGamepadInputSharing;
	static const TCHAR* const ToggleMouseInputSharing;
	
	FImGuiModuleCommands(FImGuiModuleProperties& InProperties);

	void SetKeyBinding(const TCHAR* CommandName, const FImGuiKeyInfo& KeyInfo);

private:

	void ToggleInputImpl();
	void ToggleImGuiImpl();
	void ToggleKeyboardNavigationImpl();
	void ToggleGamepadNavigationImpl();
	void ToggleKeyboardInputSharingImpl();
	void ToggleGamepadInputSharingImpl();
	void ToggleMouseInputSharingImpl();
	
	FImGuiModuleProperties& Properties;

	FAutoConsoleCommand ToggleInputCommand;
	FAutoConsoleCommand ToggleImGuiCommand;
	FAutoConsoleCommand ToggleKeyboardNavigationCommand;
	FAutoConsoleCommand ToggleGamepadNavigationCommand;
	FAutoConsoleCommand ToggleKeyboardInputSharingCommand;
	FAutoConsoleCommand ToggleGamepadInputSharingCommand;
	FAutoConsoleCommand ToggleMouseInputSharingCommand;
};
