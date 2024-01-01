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
	}

	links
	{
		"DSMgine"
	}

	postbuildcommands
	{
		-- '{COPY} ".txt" "%{cfg.targetdir}"'
	}

	filter "configurations:Debug"
		defines "DSMGEROUS_BUILD_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "DSMGEROUS_BUILD_RELEASE"
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines "DSMGEROUS_BUILD_DIST"
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
			"DSMGEROUS_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
		}

	-- Linux
	filter "system:linux"

		links
		{
			"glad",
			"glfw",
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
			"DSMGEROUS_PLATFORM_LINUX"
		}

		postbuildcommands
		{
		}