#pragma once

#include "DSMgine/Core/Base.h"

#include "SimpleLogger/SimpleLogger.hpp"

#include <iostream>

namespace DSMgine
{
	// TODO: Better logging
	class Log
	{
	public:
		static void Init();
		static void Shutdown();

		inline static std::shared_ptr<SimpleLogger::Logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<SimpleLogger::Logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<SimpleLogger::Logger> s_CoreLogger;
		static std::shared_ptr<SimpleLogger::Logger> s_ClientLogger;
	};
}

// Core Logging Macros
#define DSMGINE_CORE_UNKNOWN(...) ::DSMgine::Log::GetCoreLogger()->Log(SimpleLogger::SeverityLevels::Unknown, __VA_ARGS__)
#define DSMGINE_CORE_FAILURE(...) ::DSMgine::Log::GetCoreLogger()->Log(SimpleLogger::SeverityLevels::Failure, __VA_ARGS__)
#define DSMGINE_CORE_ERROR(...) ::DSMgine::Log::GetCoreLogger()->Log(SimpleLogger::SeverityLevels::Error, __VA_ARGS__)
#define DSMGINE_CORE_WARNING(...) ::DSMgine::Log::GetCoreLogger()->Log(SimpleLogger::SeverityLevels::Warning, __VA_ARGS__)
#define DSMGINE_CORE_IMPORTANT(...) ::DSMgine::Log::GetCoreLogger()->Log(SimpleLogger::SeverityLevels::Important, __VA_ARGS__)
#define DSMGINE_CORE_INFO(...) ::DSMgine::Log::GetCoreLogger()->Log(SimpleLogger::SeverityLevels::Info, __VA_ARGS__)
#define DSMGINE_CORE_DEBUG(...) ::DSMgine::Log::GetCoreLogger()->Log(SimpleLogger::SeverityLevels::Debug, __VA_ARGS__)
#define DSMGINE_CORE_VERBOSE(...) ::DSMgine::Log::GetCoreLogger()->Log(SimpleLogger::SeverityLevels::Verbose, __VA_ARGS__)

// Client Logging Macros
#define DSMGINE_UNKNOWN(...) ::DSMgine::Log::GetClientLogger()->Log(SimpleLogger::SeverityLevels::Unknown, __VA_ARGS__)
#define DSMGINE_FAILURE(...) ::DSMgine::Log::GetClientLogger()->Log(SimpleLogger::SeverityLevels::Failure, __VA_ARGS__)
#define DSMGINE_ERROR(...) ::DSMgine::Log::GetClientLogger()->Log(SimpleLogger::SeverityLevels::Error, __VA_ARGS__)
#define DSMGINE_WARNING(...) ::DSMgine::Log::GetClientLogger()->Log(SimpleLogger::SeverityLevels::Warning, __VA_ARGS__)
#define DSMGINE_IMPORTANT(...) ::DSMgine::Log::GetClientLogger()->Log(SimpleLogger::SeverityLevels::Important, __VA_ARGS__)
#define DSMGINE_INFO(...) ::DSMgine::Log::GetClientLogger()->Log(SimpleLogger::SeverityLevels::Info, __VA_ARGS__)
#define DSMGINE_DEBUG(...) ::DSMgine::Log::GetClientLogger()->Log(SimpleLogger::SeverityLevels::Debug, __VA_ARGS__)
#define DSMGINE_VERBOSE(...) ::DSMgine::Log::GetClientLogger()->Log(SimpleLogger::SeverityLevels::Verbose, __VA_ARGS__)