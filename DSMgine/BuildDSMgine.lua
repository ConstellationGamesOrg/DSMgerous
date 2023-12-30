project "DSMgine"
	location "../DSMgine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "Off"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	-- pchheader "DSMginePCH.hpp"
	-- pchsource "DSMgine/src/DSMginePCH.cpp"

	files
	{
		"src/**.h",
		"src/**.c",
		"src/**.hpp",
		"src/**.cpp"
	}

	includedirs
	{
		"src",
		"vendor",
		"vendor/glad/include",
		"vendor/glfw/include"
	}

	links
	{
		"glad",
		"glfw"
	}

	postbuildcommands
	{
		-- '{COPY} ".txt" "%{cfg.targetdir}"'
	}

	filter "configurations:Debug"
		defines "DSMGINE_BUILD_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "DSMGINE_BUILD_RELEASE"
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines "DSMGINE_BUILD_DIST"
		runtime "Release"
		optimize "On"
		symbols "Off"

	-- Windows
	filter "system:windows"
		systemversion "latest"

		links
		{
		}

		defines
		{
			"DSMGINE_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
		}

	-- Linux
	filter "system:linux"

		links
		{	
			"GL",
			"X11",
			"Xi",
			"Xrandr",
			"Xxf86vm",
			"Xinerama",
			"Xcursor",
			"rt",
			"m",
			"pthread"
		}

		defines
		{
			"DSMGINE_PLATFORM_LINUX"
		}

		postbuildcommands
		{
		}