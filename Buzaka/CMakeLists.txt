cmake_minimum_required(VERSION 3.20)

add_library(Buzaka STATIC)

target_sources(Buzaka
        PRIVATE "src/Buzaka/Core/Assert.h"
        PRIVATE "src/Buzaka/Core/Base.h"
        PRIVATE "src/Buzaka/Core/EntryPoint.h"
        PRIVATE "src/Buzaka/Core/Events.h"
        PRIVATE "src/Buzaka/Core/Window.h"


        PRIVATE "src/Buzaka/Core/Log.h"
        PRIVATE "src/Buzaka/Core/Log.cpp"

        PRIVATE "src/Buzaka/Core/Layer.h"
        PRIVATE "src/Buzaka/Core/Layer.cpp"

        PRIVATE "src/Buzaka/Core/LayerStack.h"
        PRIVATE "src/Buzaka/Core/LayerStack.cpp"

        PRIVATE "src/Buzaka/Core/Application.h"
        PRIVATE "src/Buzaka/Core/Application.cpp"

        PRIVATE "src/Buzaka/Events/Event.h"
        PRIVATE "src/Buzaka/Events/ApplicationEvent.h"
        PRIVATE "src/Buzaka/Events/KeyEvent.h"
        PRIVATE "src/Buzaka/Events/MouseEvent.h")

if (WIN32)
    target_sources(Buzaka
            PRIVATE "src/Platform/Windows/WindowsWindow.h"
            PRIVATE "src/Platform/Windows/WindowsWindow.cpp")
endif(WIN32)

target_include_directories(Buzaka
        PUBLIC "src")

target_precompile_headers(Buzaka
        PRIVATE "src/pch/bzpch.h")

target_compile_definitions(Buzaka
        PUBLIC "BZ_DEBUG")


# -- spdlog ----------------------
add_subdirectory("vendor/spdlog")
target_link_libraries(Buzaka
        PUBLIC spdlog::spdlog)

# -- glfw ------------------------
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("vendor/glfw")
target_link_libraries(Buzaka
        PUBLIC glfw)

# -- Glad ------------------------
add_subdirectory("vendor/Glad")
target_link_libraries(Buzaka
        PUBLIC Glad)

# -- opengl ----------------------
target_link_libraries(Buzaka
        PUBLIC opengl32)

# -- imgui -----------------------
add_subdirectory("vendor/ImGui")
target_link_libraries(Buzaka
        PUBLIC ImGui)
