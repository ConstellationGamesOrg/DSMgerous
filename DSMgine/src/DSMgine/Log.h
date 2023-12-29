#pragma once

#include "DSMgine/Base.h"

#include <iostream>

namespace DSMgine
{
	// TODO: Logger stuff
	class Log
	{
	public:
		static void Init();
		static void Shutdown();
	};
}

// Core Logging Macros
#define DSMGINE_CORE_UNKNOWN(...) std::cout << "[ENGINE]: " << __VA_ARGS__ << '\n';
#define DSMGINE_CORE_FAILURE(...) std::cout << "[ENGINE]: " << __VA_ARGS__ << '\n';
#define DSMGINE_CORE_ERROR(...) std::cout << "[ENGINE]: " << __VA_ARGS__ << '\n';
#define DSMGINE_CORE_WARNING(...) std::cout << "[ENGINE]: " << __VA_ARGS__ << '\n';
#define DSMGINE_CORE_IMPORTANT(...) std::cout << "[ENGINE]: " << __VA_ARGS__ << '\n';
#define DSMGINE_CORE_INFO(...) std::cout << "[ENGINE]: " << __VA_ARGS__ << '\n';
#define DSMGINE_CORE_DEBUG(...) std::cout << "[ENGINE]: " << __VA_ARGS__ << '\n';
#define DSMGINE_CORE_VERBOSE(...) std::cout << "[ENGINE]: " << __VA_ARGS__ << '\n';

// Client Logging Macros
#define DSMGINE_UNKNOWN(...) std::cout << "[ APP  ]: " << __VA_ARGS__ << '\n';
#define DSMGINE_FAILURE(...) std::cout << "[ APP  ]: " << __VA_ARGS__ << '\n';
#define DSMGINE_ERROR(...) std::cout << "[ APP  ]: " << __VA_ARGS__ << '\n';
#define DSMGINE_WARNING(...) std::cout << "[ APP  ]: " << __VA_ARGS__ << '\n';
#define DSMGINE_IMPORTANT(...) std::cout << "[ APP  ]: " << __VA_ARGS__ << '\n';
#define DSMGINE_INFO(...) std::cout << "[ APP  ]: " << __VA_ARGS__ << '\n';
#define DSMGINE_DEBUG(...) std::cout << "[ APP  ]: " << __VA_ARGS__ << '\n';
#define DSMGINE_VERBOSE(...) std::cout << "[ APP  ]: " << __VA_ARGS__ << '\n';