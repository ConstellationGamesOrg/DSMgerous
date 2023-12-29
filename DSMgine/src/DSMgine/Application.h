#pragma once

#include "DSMgine/Base.h"
#include "DSMgine/LayerStack.h"

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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// Implemented by CLIENT
	Application* CreateApplication();
}