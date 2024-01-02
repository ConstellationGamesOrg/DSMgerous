#include <DSMginePCH.h>

#define DSMGINE_BUILD_ID "v0.1.0"

namespace DSMgine
{
	void InitializeCore()
	{
		DSMgine::Log::Init();

		DSMGINE_CORE_VERBOSE("DSMgine " << DSMGINE_BUILD_ID);
		DSMGINE_CORE_VERBOSE("Initializing...");
	}

	void ShutdownCore()
	{
		DSMGINE_CORE_VERBOSE("Shutting down...");

		DSMgine::Log::Shutdown();
	}
}