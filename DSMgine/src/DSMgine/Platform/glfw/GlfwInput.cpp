#include <DSMginePCH.h>

#include "DSMgine/Core/Input.h"
#include "DSMgine/Core/Application.h"
#include "GlfwWindow.h"
#include "GlfwKeyCodes.h"

#include <GLFW/glfw3.h>

namespace DSMgine
{
	bool Input::IsKeyPressed(KeyCode keyCode)
	{
		auto& window = static_cast<GlfwWindow&>(Application::Get().GetWindow());
		auto state = glfwGetKey(static_cast<GLFWwindow*>(window.GetNativeWindow()), ToGlfwKeyCode(keyCode));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(MouseButton button)
	{
		auto& window = static_cast<GlfwWindow&>(Application::Get().GetWindow());

		auto state = glfwGetMouseButton(static_cast<GLFWwindow*>(window.GetNativeWindow()), ToGlfwMouseButton(button));
		return state == GLFW_PRESS;
	}

	float Input::GetMouseX()
	{
		auto [x, y] = GetMousePosition();
		return static_cast<float>(x);
	}

	float Input::GetMouseY()
	{
		auto [x, y] = GetMousePosition();
		return static_cast<float>(y);
	}

	std::pair<float, float> Input::GetMousePosition()
	{
		auto& window = static_cast<GlfwWindow&>(Application::Get().GetWindow());

		double x, y;
		glfwGetCursorPos(static_cast<GLFWwindow*>(window.GetNativeWindow()), &x, &y);
		return { static_cast<float>(x), static_cast<float>(y) };
	}
}