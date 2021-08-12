cmake_minimum_required(VERSION 3.20)
project(Buzaka)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory("Buzaka")
add_subdirectory("Sandbox")

target_compile_definitions(Buzaka
        PUBLIC "BZ_PLATFORM_WINDOWS"
        )
