cmake_minimum_required(VERSION 3.28)
project(calc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(app
    calc.cppm
    main.cpp
)

target_compile_options(app PRIVATE -fmodules-ts)

