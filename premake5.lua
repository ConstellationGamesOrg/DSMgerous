-- premake5.lua
workspace "DSMgerous"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	startproject "DSMgerous"

	-- Workspace-wide build options for MSVC
	filter "system:windows"
		buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

	flags { "MultiProcessorCompile" }

	newoption
	{
		trigger = "OpenGL-3.2",
		description = "Force the use of OpenGL 3.2"
	}

-- Directories
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- TODO: Create some global variables here for the engine to give the game things.
-- Such as any include paths the engine wants the game to have, or preprocessor defines, etc.

group "Game"
	include "DSMgerous/BuildDSMgerous.lua"
group ""

group "Core"
	include "DSMgine/BuildDSMgine.lua"
group ""

group "Dependencies"
	include "DSMgine/vendor/glad/premake5.lua"
	include "DSMgine/vendor/glfw/premake5.lua"
	include "DSMgine/vendor/ImGui/premake5.lua"
group ""