#include "DSMgine/Core/Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace DSMgine
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create(WindowProperties("DSMgine", "assets/tmp_icon.png", 1280, 720)));
		m_Window->SetEventCallback(BIND_EVENT_FN(Application, OnEvent));
		m_Window->SetVSync(true);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		OnInit();

		while (m_Running)
		{
			glClearColor(1.0f, 0.0f, 0.54901960784f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(0.0f);

			glfwSwapBuffers(static_cast<GLFWwindow*>(m_Window->GetNativeWindow()));
			glfwPollEvents();
		}

		glfwTerminate();

		OnShutdown();
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application, OnWindowResize));
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application, OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(event);
			if (event.Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowResize(WindowResizeEvent& event)
	{
		int width = event.GetWidth(), height = event.GetHeight();
		if (width == 0 || height == 0)
		{
			m_Minimized = true;
			return false;
		}
		m_Minimized = false;
		glViewport(0, 0, width, height);

		return false;
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}
}