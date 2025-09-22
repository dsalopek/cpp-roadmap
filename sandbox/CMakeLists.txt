cmake_minimum_required(VERSION 4.0)
project(sandbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_LINK_WARNING_AS_ERROR ON)
add_compile_options( -Wall -Wextra -Wshadow -Wconversion -Wpedantic)
add_executable(sandbox main.cpp
        Random.h)
