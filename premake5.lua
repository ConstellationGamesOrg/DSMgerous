-- premake5.lua
workspace "DSMgerous"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	startproject "DSMgerous"

	-- Workspace-wide build options for MSVC
	filter "system:windows"
		buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

	flags { "MultiProcessorCompile" }

-- Directories
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Game"
	include "DSMgerous/BuildDSMgerous.lua"
group ""

group "Core"
	include "DSMgine/BuildDSMgine.lua"
group ""

group "Dependencies"
	include "DSMgine/vendor/glad/premake5.lua"
	include "DSMgine/vendor/glfw/premake5.lua"
group ""