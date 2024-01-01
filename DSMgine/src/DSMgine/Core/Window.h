#pragma once

#include "DSMgine/Core/Base.h"
#include "DSMgine/Core/Event/Event.h"

#include <functional>
#include <string>

namespace DSMgine
{
	struct WindowProperties
	{
		std::string Title;
		std::string IconPath;
		uint32_t Width;
		uint32_t Height;

		WindowProperties(const std::string& title = "",
			std::string iconPath = "",
			uint32_t width = 1280,
			uint32_t height = 720)
			: Title(title), IconPath(iconPath), Width(width), Height(height)
		{
		}

		virtual ~WindowProperties() = default;
	};

	class Window
	{
	public:
		using EventCallbackFunction = std::function<void(Event&)>;

		Window() = default;
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual const std::string& GetTitle() const = 0;
		virtual void SetTitle(const std::string& title) = 0;

		virtual const std::string& GetIconPath() const = 0;
		virtual void SetIconPath(const std::string& iconPath) = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual std::pair<uint32_t, uint32_t> GetSize() const = 0;
		virtual std::pair<float, float> GetWindowPosition() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProperties& properties = WindowProperties());
	};
}