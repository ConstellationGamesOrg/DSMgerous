#pragma once

#include "DSMgine/Core/KeyCodes.h"

namespace DSMgine
{
	int ToGlfwKeyCode(KeyCode keyCode);
	int ToGlfwMouseButton(MouseButton mouseButton);

	KeyCode ToDSMgineKeyCode(int keyCode);
	MouseButton ToDSMgineMouseButton(int mouseButton);
}