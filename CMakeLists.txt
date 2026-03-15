# Require a modern version of CMake 
cmake_minimum_required(VERSION 3.15)

# Define the Main Application project
project(SakuraVNE LANGUAGES CXX)

# ------------------------------------------------------------------------------
# Default Build Type Configuration
# ------------------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting default build type to 'Debug'")
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Enforce C++20 globally
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------------------------------------------------
# Output Directory Configuration
# ------------------------------------------------------------------------------
# We put the final executable in the exact same bin/ folder structure
set(OUTPUT_DIR_SUFFIX "$<CONFIG>-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${OUTPUT_DIR_SUFFIX}")

# ------------------------------------------------------------------------------
# Subdirectories (Dependencies)
# ------------------------------------------------------------------------------
# 1. Bring in the Engine Core (This automatically brings in SDL3, ImGui, and spdlog)
add_subdirectory(libs/SakuraCore)

# 2. Bring in the Editor-specific UI library
add_subdirectory(libs/imgui-node-editor)

# ------------------------------------------------------------------------------
# Source Gathering
# ------------------------------------------------------------------------------
# Gather all files in the Editor's src folder (primarily main.cpp for now)
file(GLOB_RECURSE SAKURA_VNE_SRCS "SakuraVNE/src/*.cpp" "SakuraVNE/src/*.h")

# ------------------------------------------------------------------------------
# SakuraVNE Executable Target
# ------------------------------------------------------------------------------
add_executable(SakuraVNE ${SAKURA_VNE_SRCS})

# ------------------------------------------------------------------------------
# Includes & Linking
# ------------------------------------------------------------------------------
# Note: We do NOT need to include SDL3 or SakuraCore/src here!
# SakuraCore exports those paths automatically because we used PUBLIC in its CMake.
target_include_directories(SakuraVNE PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "libs/imgui-node-editor"
    "libs/SakuraCore/SakuraCore/src"
)

# Link the core engine and the node editor.
target_link_libraries(SakuraVNE PRIVATE
    SakuraCore
    ImGuiNodeEditor
)

# ------------------------------------------------------------------------------
# Platform & Configuration Filters
# ------------------------------------------------------------------------------
if(WIN32)
    target_compile_definitions(SakuraVNE PRIVATE PLATFORM_WINDOWS)
    target_link_options(SakuraVNE PRIVATE "/NODEFAULTLIB:MSVCRT")
elseif(UNIX AND NOT APPLE)
    target_compile_definitions(SakuraVNE PRIVATE PLATFORM_LINUX)
endif()

# Debug vs Release definitions
target_compile_definitions(SakuraVNE PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:RELEASE>
)
