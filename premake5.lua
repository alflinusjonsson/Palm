workspace "Palm"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Palm"
	location "Palm"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pmpch.h"
	pchsource "Palm/src/pmpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PM_PLATFORM_WINDOWS",
			"PM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PM_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Palm/vendor/spdlog/include",
		"Palm/src"
	}

	links
	{
		"Palm"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PM_DIST"
		optimize "On"