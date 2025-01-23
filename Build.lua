-- premake5.lua
workspace "Tetris"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Tetris"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

include "Tetris/BuildTetris.lua"