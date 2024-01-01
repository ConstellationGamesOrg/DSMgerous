#pragma once

#include "DSMgine/Core/Window.h"

#include <GLFW/glfw3.h>

namespace DSMgine
{
	class GlfwWindow : public Window
	{
	public:
		GlfwWindow(const WindowProperties& properties);
		virtual ~GlfwWindow();

		void OnUpdate() override;

		void SetEventCallback(const EventCallbackFunction& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		const std::string& GetTitle() const override { return m_Data.Title; }
		void SetTitle(const std::string& title) override;

		const std::string& GetIconPath() const override { return m_Data.IconPath; }
		void SetIconPath(const std::string& iconPath) override;

		uint32_t GetWidth() const override { return m_Data.Width; }
		uint32_t GetHeight() const override { return m_Data.Height; }
		std::pair<uint32_t, uint32_t> GetSize() const override { return { m_Data.Width, m_Data.Height }; }
		std::pair<float, float> GetWindowPosition() const override;

		void* GetNativeWindow() const override { return m_Window; }

	private:
		virtual void Init(const WindowProperties& properties);
		virtual void Shutdown();

		virtual void LoadIcon(const std::string& iconPath);

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			GLFWimage Icon[1];
			std::string IconPath;
			uint32_t Width, Height;
			bool VSync;

			EventCallbackFunction EventCallback;
		};

		WindowData m_Data;
		float m_LastFrameTime = 0.0f;
	};
}