#pragma once

#include "DSMgine/Core/KeyCodes.h"

#include <utility>

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