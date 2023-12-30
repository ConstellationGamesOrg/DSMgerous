#pragma once

#include "DSMgine/Base.h"
#include "DSMgine/Log.h"
#include "DSMgine/LayerStack.h"

#include "DSMgine/Event/Event.h"
#include "DSMgine/Event/ApplicationEvent.h"
#include "DSMgine/Event/KeyEvent.h"
#include "DSMgine/Event/MouseEvent.h"

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

		virtual void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowResize(WindowResizeEvent& event);
		bool OnWindowClose(WindowCloseEvent& event);

	private:
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// Implemented by CLIENT
	Application* CreateApplication();
}