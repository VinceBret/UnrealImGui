// Distributed under the MIT License (MIT) (see accompanying LICENSE file)

#pragma once


/** Properties that define state of the ImGui module. */
class IMGUI_API FImGuiModuleProperties
{
public:

	/** Check whether input is enabled. */
	bool IsInputEnabled() const { return bInputEnabled; }
	bool IsImGuiEnabled() const { return bImGuiEnabled; }

	/** Enable or disable ImGui input. */
	void SetImGuiEnabled(bool bEnabled) { bImGuiEnabled = bEnabled; }

	/** Toggle ImGui input. */
	void ToggleImGui() { SetImGuiEnabled(!IsImGuiEnabled()); }

	/** Check whether keyboard navigation is enabled. */
	bool IsKeyboardNavigationEnabled() const { return bKeyboardNavigationEnabled; }

	/** Enable or disable keyboard navigation. */
	void SetKeyboardNavigationEnabled(bool bEnabled) { bKeyboardNavigationEnabled = bEnabled; }

	/** Toggle keyboard navigation. */
	void ToggleKeyboardNavigation() { SetKeyboardNavigationEnabled(!IsKeyboardNavigationEnabled()); }

	/** Check whether gamepad navigation is enabled. */
	bool IsGamepadNavigationEnabled() const { return bGamepadNavigationEnabled; }

	/** Enable or disable gamepad navigation. */
	void SetGamepadNavigationEnabled(bool bEnabled) { bGamepadNavigationEnabled = bEnabled; }

	/** Toggle gamepad navigation. */
	void ToggleGamepadNavigation() { SetGamepadNavigationEnabled(!IsGamepadNavigationEnabled()); }

	/** Check whether keyboard input is shared with game. */
	bool IsKeyboardInputShared() const { return bKeyboardInputShared; }

	/** Set whether keyboard input should be shared with game. */
	void SetKeyboardInputShared(bool bShared) { bKeyboardInputShared = bShared; }

	/** Toggle whether keyboard input should be shared with game. */
	void ToggleKeyboardInputSharing() { SetKeyboardInputShared(!IsKeyboardInputShared()); }

	/** Check whether gamepad input is shared with game. */
	bool IsGamepadInputShared() const { return bGamepadInputShared; }

	/** Set whether gamepad input should be shared with game. */
	void SetGamepadInputShared(bool bShared) { bGamepadInputShared = bShared; }

	/** Toggle whether gamepad input should be shared with game. */
	void ToggleGamepadInputSharing() { SetGamepadInputShared(!IsGamepadInputShared()); }
	
private:

	bool bInputEnabled = true;
	bool bImGuiEnabled = false;

	bool bKeyboardNavigationEnabled = false;
	bool bGamepadNavigationEnabled = false;

	bool bKeyboardInputShared = false;
	bool bGamepadInputShared = false;
};
