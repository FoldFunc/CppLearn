cmake_minimum_required(VERSION 3.25)

project(CMAKETest LANGUAGES CXX)

# Require C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENTIONS OFF)

add_executable(main src/main.cpp)
