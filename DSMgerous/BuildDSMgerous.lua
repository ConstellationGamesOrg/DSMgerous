project "DSMgerous"
	location "../DSMgerous"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "Off"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

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
		"../DSMgine/src",
		"../DSMgine/vendor",
		"../DSMgine/vendor/SimpleLogger3.0"
	}

	links
	{
		"DSMgine",
		"ImGui"
	}

	postbuildcommands
	{
	}

	filter "configurations:Debug"
		defines { "DSMGEROUS_BUILD_DEBUG", "DSMGINE_BUILD_DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "DSMGEROUS_BUILD_RELEASE", "DSMGINE_BUILD_RELEASE" }
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines { "DSMGEROUS_BUILD_DIST", "DSMGINE_BUILD_DIST" }
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
			"DSMGEROUS_PLATFORM_WINDOWS",
			"DSMGINE_PLATFORM_WINDOWS",
		}

		postbuildcommands
		{
			'{COPY} "../DSMgine/assets" "%{cfg.targetdir}/assets"', -- We copy the engine's assets first,
			'{COPY} "assets" "%{cfg.targetdir}/assets"'             -- so the game's assets override any duplicated files.
		}

	-- Linux
	filter "system:linux"

		links
		{
			"glad",
			"glfw",
			"ImGui",
			"imgui",
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
			"DSMGEROUS_PLATFORM_LINUX",
			"DSMGINE_PLATFORM_LINUX"
		}

		postbuildcommands
		{
			'{COPY} "../DSMgine/assets" "%{cfg.targetdir}"', -- We copy the engine's assets first,
			'{COPY} "assets" "%{cfg.targetdir}"'             -- so the game's assets override any duplicated files.
		}
