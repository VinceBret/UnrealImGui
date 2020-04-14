#include "ImGuiDebugTool.h"
#include "ImGuiModuleManager.h"
#include "Widgets/SImGuiWidget.h"

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



IMPLEMENT_IMGUI_DEBUGTOOL(ImGuiDebugTool_ImGuiDebug)

ImGuiDebugTool_ImGuiDebug::ImGuiDebugTool_ImGuiDebug()
	: ImGuiDebugTool()
{
}

ImGuiDebugTool_ImGuiDebug::~ImGuiDebugTool_ImGuiDebug()
{
}

void ImGuiDebugTool_ImGuiDebug::AddWidget(SImGuiWidget* widget)
{
	m_Widgets.AddUnique(widget);
}

void ImGuiDebugTool_ImGuiDebug::RemoveWidget(SImGuiWidget* widget)
{
	m_Widgets.Remove(widget);
}

void ImGuiDebugTool_ImGuiDebug::OnDisplay()
{
	for (SImGuiWidget* widget : m_Widgets)
	{
		widget->DisplayImGuiDebug();
	}
}

IMPLEMENT_IMGUI_DEBUGTOOL(ImGuiDebugTool_Demo)


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
