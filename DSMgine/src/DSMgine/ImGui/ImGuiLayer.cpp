#include <DSMginePCH.h>

#include "DSMgine/ImGui/ImGuiLayer.h"

#include <imgui.h>

namespace DSMgine
{
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGui")
	{
	}

	ImGuiLayer::ImGuiLayer(const std::string& name)
		: Layer(name)
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
	}

	void ImGuiLayer::OnDetach()
	{
	}

	void ImGuiLayer::OnUpdate(float ts)
	{
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		DSMGINE_CORE_VERBOSE(GetName() << ": " << event);

		// TEMP: Handle all the keyboard events, as a test
		if (event.IsInCategory(EventCategoryKeyboard))
			event.Handled = true;
	}
}