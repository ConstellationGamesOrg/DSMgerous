#include <DSMgine.h>

#include "DSMgine/ImGui/ImGuiLayer.h"

static void ImGuiShowHelpMarker(const char* description)
{
	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(description);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

class GameLayer : public DSMgine::Layer
{
public:
	GameLayer()
		: Layer("GameLayer")
	{
	}

	virtual ~GameLayer()
	{
	}

	virtual void OnAttach() override
	{
		DSMGINE_VERBOSE("GameLayer::OnAttach");
	}

	virtual void OnDetach() override
	{
		DSMGINE_VERBOSE("GameLayer::OnDetach");
	}

	virtual void OnUpdate(float ts) override
	{
		//DSMGINE_VERBOSE("GameLayer::OnUpdate");
	}

	virtual void OnImGuiRender() override
	{
		//static bool show_demo_window = true;
		//if (show_demo_window)
		//	ImGui::ShowDemoWindow(&show_demo_window);

		ImGui::StyleColorsClassic();

		ImGui::Begin("EditorLayer0");
		ImGui::Text("Window title %s", DSMgine::Application::Get().GetWindow().GetTitle().c_str());
		ImGui::Text("Window size %d, %d", DSMgine::Application::Get().GetWindow().GetSize().first, DSMgine::Application::Get().GetWindow().GetSize().second);
		ImGui::Text("Window width %d", DSMgine::Application::Get().GetWindow().GetWidth());
		ImGui::Text("Window height %d", DSMgine::Application::Get().GetWindow().GetHeight());
		ImGui::Text("Window position %d, %d", DSMgine::Application::Get().GetWindow().GetWindowPosition().first, DSMgine::Application::Get().GetWindow().GetWindowPosition().second);
		ImGui::Dummy(ImVec2(0.0f, 10.0f));
		ImGui::Text("Hover over this ->");
		ImGui::SameLine();
		ImGuiShowHelpMarker(
			"In the ImGui docking branch, you can dock any window into another even without an ImGui::DockSpace(). Test it!" "\n"
		);
		ImGui::End();

		ImGui::Begin("EditorLayer1");
		static float color[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
		ImGui::ColorPicker4("Color", (float*)&color);
		ImGuiShowHelpMarker(
			"In the ImGui docking branch, you can dock any window into another even without an ImGui::DockSpace(). Test it!" "\n"
		);
		ImGui::End();
	}

	virtual void OnEvent(DSMgine::Event& event) override
	{
		DSMGINE_VERBOSE(event.ToString());
	}
};

class DSMgerous : public DSMgine::Application
{
public:
	DSMgerous()
	{
	}

	virtual ~DSMgerous()
	{
	}

	virtual void OnInit() override
	{
		PushLayer(new GameLayer());
	}

	virtual void OnShutdown() override
	{
	}
};

DSMgine::Application* DSMgine::CreateApplication()
{
	return new DSMgerous();
}