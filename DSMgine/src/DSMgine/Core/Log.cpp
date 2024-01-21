#include <DSMginePCH.h>

#include "DSMgine/Core/Log.h"

namespace DSMgine
{
	std::shared_ptr<SimpleLogger::Logger> Log::s_CoreLogger;
	std::shared_ptr<SimpleLogger::Logger> Log::s_ClientLogger;

	void Log::Init()
	{
		{
			s_CoreLogger = std::make_unique<SimpleLogger::Logger>(SimpleLogger::Logger());
			auto consoleTarget = s_CoreLogger->AddTarget(new SimpleLogger::ConsoleTarget());
			auto fileTarget = s_CoreLogger->AddTarget(new SimpleLogger::FileTarget("Engine.log"));
			s_CoreLogger->SetPrefix("[ENIGNE]");
			s_CoreLogger->SetVerboseLevel(SimpleLogger::SeverityLevels::Verbose);
		}

		{
			s_ClientLogger = std::make_unique<SimpleLogger::Logger>(SimpleLogger::Logger());
			auto consoleTarget = s_ClientLogger->AddTarget(new SimpleLogger::ConsoleTarget());
			auto fileTarget = s_ClientLogger->AddTarget(new SimpleLogger::FileTarget("App.log"));
			s_ClientLogger->SetPrefix("[ APP  ]");
			s_ClientLogger->SetVerboseLevel(SimpleLogger::SeverityLevels::Verbose);
		}
	}

	void Log::Shutdown()
	{
	}
}