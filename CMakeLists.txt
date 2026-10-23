cmake_minimum_required(VERSION 3.10.0)
project(lab3 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    add_compile_options(/W3)
    add_compile_options(/std:c++20)
    add_compile_options(/EHsc)
    add_compile_options(/utf-8)
    add_compile_options(/O2)
else()
    add_compile_options(-Wall)
    add_compile_options(-std=c++20)
    add_compile_options(-fexceptions)
    add_compile_options(-O3)
endif()

add_executable(lab3
    program.cpp
)

if (NOT MSVC)
    find_package(Threads REQUIRED)
    target_link_libraries(lab3 Threads::Threads)
endif()
