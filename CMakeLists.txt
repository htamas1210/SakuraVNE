cmake_minimum_required(VERSION 3.15)

project(SakuraVNE LANGUAGES CXX)

#TODO: add ctest for automatic test running with catch2

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting default build type to 'Debug'")
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

#TODO: think about upgrading to cpp23
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------------------------------------------------
# Output Directory Configuration
# ------------------------------------------------------------------------------
set(OUTPUT_DIR_SUFFIX "$<CONFIG>-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${OUTPUT_DIR_SUFFIX}")

# ------------------------------------------------------------------------------
# Subdirectories (Dependencies)
# ------------------------------------------------------------------------------
add_subdirectory(libs/SakuraCore)
add_subdirectory(libs/imgui-node-editor)


file(GLOB_RECURSE SAKURA_VNE_SRCS "SakuraVNE/src/*.cpp" "SakuraVNE/src/*.h")
add_executable(SakuraVNE ${SAKURA_VNE_SRCS})

# Note: We do NOT need to include SDL3 or SakuraCore/src here!
# SakuraCore exports those paths automatically because we used PUBLIC in its CMake.
# TODO: either the comment is shit or something is not set correctly to include Core/src, or this just means the header files
target_include_directories(SakuraVNE PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "libs/imgui-node-editor"
    "libs/SakuraCore/SakuraCore/src"
)

target_link_libraries(SakuraVNE PRIVATE
    SakuraCore
    ImGuiNodeEditor
)

if(WIN32)
    target_compile_definitions(SakuraVNE PRIVATE PLATFORM_WINDOWS)
    target_link_options(SakuraVNE PRIVATE "/NODEFAULTLIB:MSVCRT")
elseif(UNIX AND NOT APPLE)
    target_compile_definitions(SakuraVNE PRIVATE PLATFORM_LINUX)
endif()

# TODO: check how to properly use this, now it is just "overwritten" with -DCMAKE_BUILD_TYPE
target_compile_definitions(SakuraVNE PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:RELEASE>
)
