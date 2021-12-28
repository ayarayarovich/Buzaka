cmake_minimum_required(VERSION 3.20)

add_library(Buzaka STATIC)

target_sources(Buzaka
        PRIVATE "src/Buzaka/Core/Assert.h"
        PRIVATE "src/Buzaka/Core/Base.h"
        PRIVATE "src/Buzaka/Core/EntryPoint.h"
        PRIVATE "src/Buzaka/Core/Events.h"
        PRIVATE "src/Buzaka/Core/Window.h"
        PRIVATE "src/Buzaka/Core/Input.h"
        PRIVATE "src/Buzaka/Core/KeyCodes.h"
        PRIVATE "src/Buzaka/Core/MouseButtonCodes.h"


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
        PRIVATE "src/Buzaka/Events/MouseEvent.h"

        PRIVATE "src/Buzaka/ImGui/ImGuiLayer.h"
        PRIVATE "src/Buzaka/ImGui/ImGuiLayer.cpp")

if (WIN32)
    target_compile_definitions(Buzaka
            PUBLIC "BZ_PLATFORM_WINDOWS")
    target_sources(Buzaka
            PRIVATE "src/Platform/Windows/WindowsWindow.h"
            PRIVATE "src/Platform/Windows/WindowsWindow.cpp"

            PRIVATE "src/Platform/Windows/WindowsInput.h"
            PRIVATE "src/Platform/Windows/WindowsInput.cpp"

            PRIVATE "src/Platform/OpenGL/ImGuiOpenGLRenderer.h"
            PRIVATE "src/Platform/OpenGL/ImGuiOpenGLRenderer.cpp")
endif(WIN32)

target_include_directories(Buzaka
        PUBLIC "src")

target_precompile_headers(Buzaka
        PRIVATE "src/pch/bzpch.h")

target_compile_definitions(Buzaka
        PUBLIC "$<$<CONFIG:Debug>:BZ_DEBUG>")

# -- spdlog ----------------------
find_package(spdlog REQUIRED)
target_link_libraries(Buzaka
        PUBLIC spdlog::spdlog spdlog::spdlog_header_only)

# -- glfw ------------------------
find_package(glfw3 REQUIRED)
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
find_package(imgui REQUIRED)
target_link_libraries(Buzaka
        PUBLIC imgui::imgui)
target_compile_definitions(Buzaka
        PUBLIC "IMGUI_IMPL_OPENGL_LOADER_GLAD")

# -- glm -------------------------
find_package(glm REQUIRED)
target_link_libraries(Buzaka
        PRIVATE glm::glm)
