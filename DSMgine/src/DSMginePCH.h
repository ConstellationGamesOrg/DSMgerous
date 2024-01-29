#pragma once

#ifdef DSMGINE_PLATFORM_WINDOWS
#include <Windows.h>
#elif defined DSMGINE_PLATFORM_LINUX
#include <signal.h>
#endif

#include <algorithm>
#include <array>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <DSMgine/Core/Base.h>
#include <DSMgine/Core/Assert.h>
#include <DSMgine/Core/Event/Event.h>
#include <DSMgine/Core/Log.h>