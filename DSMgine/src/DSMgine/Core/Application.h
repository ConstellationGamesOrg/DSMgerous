#pragma once

#include "DSMgine/Core/Base.h"
#include "DSMgine/Core/Log.h"
#include "DSMgine/Core/LayerStack.h"
#include "DSMgine/Core/Window.h"

#include "DSMgine/Core/Event/Event.h"
#include "DSMgine/Core/Event/ApplicationEvent.h"
#include "DSMgine/Core/Event/KeyEvent.h"
#include "DSMgine/Core/Event/MouseEvent.h"

#include <memory>

namespace DSMgine
{
	struct ApplicationProperties
	{
		std::string Name;
		std::string IconPath;
		uint32_t WindowWidth, WindowHeight;
	};

	class Application
	{
	public:
		Application(const ApplicationProperties& properties = { "DSMgine", "", 1280, 720});
		virtual ~Application();

		void Run();

		virtual void OnInit() {};
		virtual void OnShutdown() {};
		virtual void OnUpdate(float ts) {};

		virtual void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowResize(WindowResizeEvent& event);
		bool OnWindowClose(WindowCloseEvent& event);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
	};

	// Implemented by CLIENT
	Application* CreateApplication();
}
