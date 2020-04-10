// Distributed under the MIT License (MIT) (see accompanying LICENSE file)

#include "ImGuiPrivatePCH.h"

#include "ImGuiModuleCommands.h"

#include "Utilities/DebugExecBindings.h"


const TCHAR* const FImGuiModuleCommands::ToggleInput = TEXT("ImGui.ToggleInput");
const TCHAR* const FImGuiModuleCommands::ToggleImGui = TEXT("ImGui.ToggleImGui");
const TCHAR* const FImGuiModuleCommands::ToggleKeyboardNavigation = TEXT("ImGui.ToggleKeyboardNavigation");
const TCHAR* const FImGuiModuleCommands::ToggleGamepadNavigation = TEXT("ImGui.ToggleGamepadNavigation");
const TCHAR* const FImGuiModuleCommands::ToggleKeyboardInputSharing = TEXT("ImGui.ToggleKeyboardInputSharing");
const TCHAR* const FImGuiModuleCommands::ToggleGamepadInputSharing = TEXT("ImGui.ToggleGamepadInputSharing");
const TCHAR* const FImGuiModuleCommands::ToggleMouseInputSharing = TEXT("ImGui.ToggleMouseInputSharing");

FImGuiModuleCommands::FImGuiModuleCommands(FImGuiModuleProperties& InProperties)
	: Properties(InProperties)
	, ToggleInputCommand(ToggleInput,
		TEXT("Toggle ImGui input mode."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleInputImpl))
	, ToggleImGuiCommand(ToggleImGui,
		TEXT("Toggle ImGui debug."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleImGuiImpl))
	, ToggleKeyboardNavigationCommand(ToggleKeyboardNavigation,
		TEXT("Toggle ImGui keyboard navigation."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleKeyboardNavigationImpl))
	, ToggleGamepadNavigationCommand(ToggleGamepadNavigation,
		TEXT("Toggle ImGui gamepad navigation."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleGamepadNavigationImpl))
	, ToggleKeyboardInputSharingCommand(ToggleKeyboardInputSharing,
		TEXT("Toggle ImGui keyboard input sharing."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleKeyboardInputSharingImpl))
	, ToggleGamepadInputSharingCommand(ToggleGamepadInputSharing,
		TEXT("Toggle ImGui gamepad input sharing."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleGamepadInputSharingImpl))
	, ToggleMouseInputSharingCommand(ToggleMouseInputSharing,
		TEXT("Toggle ImGui mouse input sharing."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleMouseInputSharingImpl))
{
}

void FImGuiModuleCommands::SetKeyBinding(const TCHAR* CommandName, const FImGuiKeyInfo& KeyInfo)
{
	DebugExecBindings::UpdatePlayerInputs(KeyInfo, CommandName);
}

void FImGuiModuleCommands::ToggleInputImpl()
{
	Properties.ToggleInput();
}

void FImGuiModuleCommands::ToggleImGuiImpl()
{
	Properties.ToggleImGui();
}

void FImGuiModuleCommands::ToggleKeyboardNavigationImpl()
{
	Properties.ToggleKeyboardNavigation();
}

void FImGuiModuleCommands::ToggleGamepadNavigationImpl()
{
	Properties.ToggleGamepadNavigation();
}

void FImGuiModuleCommands::ToggleKeyboardInputSharingImpl()
{
	Properties.ToggleKeyboardInputSharing();
}

void FImGuiModuleCommands::ToggleGamepadInputSharingImpl()
{
	Properties.ToggleGamepadInputSharing();
}

void FImGuiModuleCommands::ToggleMouseInputSharingImpl()
{
	Properties.ToggleMouseInputSharing();
}

