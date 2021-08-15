cmake_minimum_required(VERSION 3.20)

add_library(Buzaka STATIC)

target_sources(Buzaka
        PRIVATE "src/Buzaka/Core/Log.cpp"
        PRIVATE "src/Buzaka/Core/Layer.cpp"
        PRIVATE "src/Buzaka/Core/LayerStack.cpp"
        PRIVATE "src/Buzaka/Core/Application.cpp")

if (WIN32)
    target_sources(Buzaka
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

