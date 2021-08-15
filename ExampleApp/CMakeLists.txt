cmake_minimum_required(VERSION 3.20)

add_executable(ExampleApp
        "src/ExampleApp.cpp"
        )

target_link_libraries(ExampleApp
        PUBLIC Buzaka)
