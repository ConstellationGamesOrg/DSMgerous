#pragma once

#include <utility>

typedef uint16_t KeyCode; // TODO: Keycodes
typedef uint16_t MouseButton; // TODO: Mousebuttons

namespace DSMgine
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode keyCode);

		static bool IsMouseButtonPressed(MouseButton button);
		static float GetMouseX();
		static float GetMouseY();
		static std::pair<float, float> GetMousePosition();
	};
}