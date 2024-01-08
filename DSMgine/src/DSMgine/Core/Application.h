#pragma once

#include "DSMgine/Core/Base.h"
#include "DSMgine/Core/Log.h"
#include "DSMgine/Core/LayerStack.h"
#include "DSMgine/Core/Window.h"

#include "DSMgine/Core/Event/Event.h"
#include "DSMgine/Core/Event/ApplicationEvent.h"
#include "DSMgine/Core/Event/KeyEvent.h"
#include "DSMgine/Core/Event/MouseEvent.h"

#include "DSMgine/ImGui/ImGuiLayer.h"

#include <memory>

namespace DSMgine
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		virtual void OnInit() {};
		virtual void OnShutdown() {};
		virtual void OnUpdate(float ts) {};

		void RenderImGui();

		virtual void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		static inline Application& Get() { return *s_Instance; }

	private:
		bool OnWindowResize(WindowResizeEvent& event);
		bool OnWindowClose(WindowCloseEvent& event);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;

		static Application* s_Instance;
	};

	// Implemented by CLIENT
	Application* CreateApplication();
}
