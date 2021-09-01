cmake_minimum_required(VERSION 3.20)
project(Buzaka)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory("Buzaka")
add_subdirectory("ExampleApp")

target_compile_definitions(Buzaka
        PUBLIC "BZ_PLATFORM_WINDOWS"
        )
