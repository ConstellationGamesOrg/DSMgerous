#pragma once

#include "DSMgine/Core/Layer.h"

#include "DSMgine/Core/Event/Event.h"
#include "DSMgine/Core/Event/KeyEvent.h"
#include "DSMgine/Core/Event/MouseEvent.h"
#include "DSMgine/Core/Event/ApplicationEvent.h"

namespace DSMgine
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer(const std::string& name = "ImGui");
		virtual ~ImGuiLayer();

		virtual void OnAttach() override;
		void Begin();
		virtual void OnImGuiRender() override;
		void End();
		virtual void OnDetach() override;
	};
}