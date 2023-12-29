#pragma once

#include <functional>

namespace DSMgine
{
	void InitializeCore();
	void ShutdownCore();
}

#define BIT(x) (1 << x)
#define BIND_EVENT_FN(cs, fn) std::bind(&cs::fn, this, std::placeholders::_1)