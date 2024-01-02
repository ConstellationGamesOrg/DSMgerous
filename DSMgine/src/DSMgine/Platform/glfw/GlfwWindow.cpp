#include <DSMginePCH.h>

#include <glad/glad.h> // We need to include glad before glfw
#include "DSMgine/Platform/glfw/GlfwWindow.h"

#include "DSMgine/Core/Event/ApplicationEvent.h"
#include "DSMgine/Core/Event/KeyEvent.h"
#include "DSMgine/Core/Event/MouseEvent.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

namespace DSMgine
{
	static void GLFWErrorCallback(int error, const char* description)
	{
		DSMGINE_CORE_ERROR("GLFW Error (" << error << ") : " << description);
	}

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProperties& properties)
	{
		return new GlfwWindow(properties);
	}

	GlfwWindow::GlfwWindow(const WindowProperties& properties)
	{
		Init(properties);
	}

	GlfwWindow::~GlfwWindow()
	{
	}

	void GlfwWindow::Init(const WindowProperties& properties)
	{
		m_Data.Title = properties.Title;
		m_Data.IconPath = properties.IconPath;
		m_Data.Width = properties.Width;
		m_Data.Height = properties.Height;

		DSMGINE_CORE_INFO("Creating window " << m_Data.Title << " (" << m_Data.Width << ", " << m_Data.Height << ")");

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			if (!success)
				DSMGINE_CORE_ERROR("Could not intialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(static_cast<int>(m_Data.Width), static_cast<int>(m_Data.Height), m_Data.Title.c_str(), nullptr, nullptr);

		/* Boarderless window
		glfwWindowHint(GLFW_DECORATED, GL_FALSE);
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		window = glfwCreateWindow(static_cast<int>(m_Data.Width), static_cast<int>(m_Data.Height), m_Data.Title.c_str(), nullptr, nullptr);
		glfwSetWindowPos(window, 0, 0);
		*/

		/* Fullscreen window
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		window = glfwCreateWindow(static_cast<int>(m_Data.Width), static_cast<int>(m_Data.Height), m_Data.Title.c_str(), glfwGetPrimaryMonitor(), nullptr);
		*/

		glfwMakeContextCurrent(m_Window);
		LoadIcon(m_Data.IconPath);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		if (!status)
			DSMGINE_CORE_ERROR("Failed to initialize glad!");
		glfwSetWindowUserPointer(m_Window, &m_Data);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			auto& data = *(static_cast<WindowData*>(glfwGetWindowUserPointer(window)));

			WindowResizeEvent event(static_cast<unsigned int>(width), static_cast<unsigned int>(height));
			data.EventCallback(event);
			data.Width = width;
			data.Height = height;
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			auto& data = *(static_cast<WindowData*>(glfwGetWindowUserPointer(window)));

			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			auto& data = *(static_cast<WindowData*>(glfwGetWindowUserPointer(window)));

			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);
				data.EventCallback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, 1);
				data.EventCallback(event);
				break;
			}
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int codepoint)
		{
			auto& data = *(static_cast<WindowData*>(glfwGetWindowUserPointer(window)));

			KeyTypedEvent event(codepoint);
			data.EventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			auto& data = *(static_cast<WindowData*>(glfwGetWindowUserPointer(window)));

			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
				break;
			}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			auto& data = *(static_cast<WindowData*>(glfwGetWindowUserPointer(window)));

			MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double width, double height)
		{
			auto& data = *(static_cast<WindowData*>(glfwGetWindowUserPointer(window)));

			MouseMovedEvent event(static_cast<float>(width), static_cast<float>(height));
			data.EventCallback(event);
		});
	}

	void GlfwWindow::Shutdown()
	{
		glfwTerminate();
	}

	void GlfwWindow::LoadIcon(const std::string& iconPath)
	{
		if (iconPath == "")
		{
			glfwSetWindowIcon(m_Window, 0, nullptr);
			return;
		}

		m_Data.Icon[0].pixels = stbi_load(iconPath.c_str(), &m_Data.Icon[0].width, &m_Data.Icon[0].height, 0, 4);
		glfwSetWindowIcon(m_Window, 1, m_Data.Icon);
		stbi_image_free(m_Data.Icon[0].pixels);
	}

	void GlfwWindow::SetTitle(const std::string& title)
	{
		m_Data.Title = title;
		glfwSetWindowTitle(m_Window, m_Data.Title.c_str());
	}

	void GlfwWindow::SetIconPath(const std::string& iconPath)
	{
		m_Data.IconPath = iconPath;
		LoadIcon(m_Data.IconPath);
	}

	inline std::pair<float, float> GlfwWindow::GetWindowPosition() const
	{
		int width, height;
		glfwGetWindowPos(m_Window, &width, &height);
		return { width, height };
	}

	void GlfwWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);

		float time = glfwGetTime();
		float delta = time - m_LastFrameTime;
		m_LastFrameTime = time;
	}

	void GlfwWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool GlfwWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}