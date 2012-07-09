require "config/premake4/functions"
require "config/premake4/qt-support"

solution "LatexSongbook"
    configurations { "Debug", "Release" }

    flags { "ExtraWarnings" }

    configuration { "linux or bsd or solaris" }
        defines { "UNIX" }

    configuration { "windows" }
        defines { "WINDOWS" }

    configuration { "linux", "gmake" }
        buildoptions { "-std=c++0x" }

    configuration "Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

    configuration "Release"
        flags { "Optimize" }

    project "LatexSongbook"
        kind "WindowedApp"
        language "C++"

        targetdir "bin"

        uses "QtGui"
        uses "QtTest"
        uses "QtSql"

        require_pkg_config()

        includedirs { "./src" }

        files {
            "src/main.cpp",
            "src/*.hpp",
            "src/*.cpp",
            "ui/*.ui",
            "res/*.qrc"
        }
