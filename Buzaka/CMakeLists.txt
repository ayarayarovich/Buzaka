cmake_minimum_required(VERSION 3.20)

set(BUZAKA_SOURCE_FILES
        "src/Buzaka/Core/Log.cpp"
        "src/Buzaka/Core/Application.cpp")

if (WIN32)
    list(APPEND BUZAKA_SOURCE_FILES
            "src/Platform/Windows/WindowsWindow.cpp")
endif(WIN32)


add_library(Buzaka STATIC ${BUZAKA_SOURCE_FILES})

target_include_directories(Buzaka
        PUBLIC "src")

target_precompile_headers(Buzaka
        PRIVATE "src/pch/bzpch.h")

target_compile_definitions(Buzaka
        PUBLIC "BZ_DEBUG")


# ==== Libs ======================
# -- spdlog ----------------------
add_subdirectory("vendor/spdlog")
target_link_libraries(Buzaka
        PUBLIC spdlog::spdlog)
# --------------------------------

# -- glfw ------------------------
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("vendor/glfw")
target_link_libraries(Buzaka
        PUBLIC glfw)
# --------------------------------
# ================================

