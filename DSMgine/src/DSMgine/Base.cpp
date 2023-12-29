#include "DSMgine/Base.h"

#define DSMGINE_BUILD_ID "v0.1.0"

#include <iostream> // TMP!

namespace DSMgine
{
	void InitializeCore()
	{
		// TODO: Logger

		//DSMgine::Log::Init();

		std::cout << "DSMgine " << DSMGINE_BUILD_ID << '\n';
		std::cout << "Initializing...\n";
	}

	void ShutdownCore()
	{
		std::cout << "Shutting down...\n";

		//DSMgine::Log::Shutdown();
	}
}