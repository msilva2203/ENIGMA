workspace "Enigma"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Distribution"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Enigma"
    location "Enigma"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/Vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ENIGMA_PLATFORM_WINDOWS",
            "ENIGMA_BUILD"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath}/ ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "ENIGMA_CONFIG_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ENIGMA_CONFIG_RELEASE"
        optimize "On"

    filter "configurations:Distribution"
        defines "ENIGMA_CONFIG_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "Enigma/Vendor/spdlog/include",
        "Enigma/Source"
    }

    links
    {
        "Enigma"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ENIGMA_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "ENIGMA_CONFIG_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ENIGMA_CONFIG_RELEASE"
        optimize "On"

    filter "configurations:Distribution"
        defines "ENIGMA_CONFIG_DIST"
        optimize "On"
