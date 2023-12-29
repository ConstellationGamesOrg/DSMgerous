#pragma once

#include "DSMgine/Base.h"

namespace DSMgine
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Implemented by CLIENT
	Application* CreateApplication();
}