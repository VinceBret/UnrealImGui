#pragma once

#define DECLARE_IMGUI_DEBUGTOOL(ImGuiDebugToolClass) \
public:\
static ImGuiDebugToolClass* GetInstance() {return &ms_Instance;} \
private: \
static ImGuiDebugToolClass ms_Instance;

#define IMPLEMENT_IMGUI_DEBUGTOOL(ImGuiDebugToolClass) \
ImGuiDebugToolClass ImGuiDebugToolClass::ms_Instance;

class IMGUI_API ImGuiDebugTool
{
public:
	ImGuiDebugTool();
	virtual ~ImGuiDebugTool();

	virtual FString  GetMenuTitle() = 0;
	virtual const char* GetWndTitle() = 0;
	void Display();
	void Toggle() { m_IsActive = !m_IsActive; }
	bool IsActive() const { return m_IsActive; }

	void GetMenuPath(TArray<FString>& menuPath);

protected:
	virtual void OnDisplay() = 0;
	bool m_IsActive{ false };
	bool m_CreateWnd{ true };
};

class ImGuiDebugTool_Demo : public ImGuiDebugTool
{
	DECLARE_IMGUI_DEBUGTOOL(ImGuiDebugTool_Demo)

public:
	ImGuiDebugTool_Demo();
	virtual ~ImGuiDebugTool_Demo();

	FString GetMenuTitle() override { return TEXT("Demo:Demo"); }
	const char* GetWndTitle() override { return "Demo"; }

protected:
	void OnDisplay() override;
};

