#include "ImGuiDebugTool.h"
#include "ImGuiModuleManager.h"

IMPLEMENT_IMGUI_DEBUGTOOL(ImGuiDebugTool_Demo)

ImGuiDebugTool::ImGuiDebugTool()
{
	FImGuiModule::Get().GetImGuiModuleManager()->RegisterDebugTool(this);
}
ImGuiDebugTool::~ImGuiDebugTool()
{
	FImGuiModule::Get().GetImGuiModuleManager()->UnregisterDebugTool(this);
}

void ImGuiDebugTool::GetMenuPath(TArray<FString>& menuPath)
{
	GetMenuTitle().ParseIntoArray(menuPath, TEXT(":"), true);
}

void ImGuiDebugTool::Display()
{
	if (m_CreateWnd)
	{
		ImGui::SetNextWindowPos(ImVec2(30, 30), ImGuiCond_FirstUseEver);

		ImGui::Begin(GetWndTitle(), &m_IsActive);
	}

	OnDisplay();
	if (m_CreateWnd)
	{
		ImGui::End();
	}

}

ImGuiDebugTool_Demo::ImGuiDebugTool_Demo()
	: ImGuiDebugTool()
{
	m_CreateWnd = false;
}

ImGuiDebugTool_Demo::~ImGuiDebugTool_Demo()
{}

void ImGuiDebugTool_Demo::OnDisplay()
{
	ImGui::ShowDemoWindow();
}
