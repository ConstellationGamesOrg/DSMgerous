#pragma once

#ifdef DSMGINE_PLATFORM_WINDOWS
#define DSMGINE_DEBUG_BREAK __debugbreak()
#elif defined DSMGINE_PLATORM_LINUX
#define DSMGINE_DEBUG_BREAK raise(SIGTRAP);
#else
#define DSMGINE_DEBUG_BREAK
#endif

#ifdef DSMGINE_BUILD_DEBUG
#define DSMGINE_ENABLE_ASSERTS
#endif

#define DSMGINE_ENABLE_VERIFY

#ifdef DSMGINE_ENABLE_ASSERTS
#define DSMGINE_CORE_ASSERT_MESSAGE_INTERNAL(...)  ::DSMgine::Log::GetCoreLogger()->Log(SimpleLogger::SeverityLevels::Error, "Assertion Failed. {0}", __VA_ARGS__)
#define DSMGINE_ASSERT_MESSAGE_INTERNAL(...)  ::DSMgine::Log::GetClientLogger()->Log(SimpleLogger::SeverityLevels::Error, "Assertion Failed. {0}", __VA_ARGS__)

#define DSMGINE_CORE_ASSERT(condition, ...) { if(!(condition)) { DSMGINE_CORE_ASSERT_MESSAGE_INTERNAL(__VA_ARGS__); DSMGINE_DEBUG_BREAK; } }
#define DSMGINE_ASSERT(condition, ...) { if(!(condition)) { DSMGINE_ASSERT_MESSAGE_INTERNAL(__VA_ARGS__); DSMGINE_DEBUG_BREAK; } }
#else
#define DSMGINE_CORE_ASSERT(condition, ...)
#define DSMGINE_ASSERT(condition, ...)
#endif

#ifdef DSMGINE_ENABLE_VERIFY
#define DSMGINE_CORE_VERIFY_MESSAGE_INTERNAL(...)  ::DSMgine::Log::GetCoreLogger()->Log(SimpleLogger::SeverityLevels::Error, "Verify Failed. {0}", __VA_ARGS__)
#define DSMGINE_VERIFY_MESSAGE_INTERNAL(...)  ::DSMgine::Log::GetClientLogger()->Log(SimpleLogger::SeverityLevels::Error, "Verify Failed. {0}", __VA_ARGS__)

#define DSMGINE_CORE_VERIFY(condition, ...) { if(!(condition)) { DSMGINE_CORE_VERIFY_MESSAGE_INTERNAL(__VA_ARGS__); DSMGINE_DEBUG_BREAK; } }
#define DSMGINE_VERIFY(condition, ...) { if(!(condition)) { DSMGINE_VERIFY_MESSAGE_INTERNAL(__VA_ARGS__); DSMGINE_DEBUG_BREAK; } }
#else
#define DSMGINE_CORE_VERIFY(condition, ...)
#define DSMGINE_VERIFY(condition, ...)
#endif
