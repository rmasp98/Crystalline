cmake_minimum_required(VERSION 3.11)
project(Crystalline)

add_subdirectory(src)
add_subdirectory(libs)
add_subdirectory(tests)

# TODO: Remove later
add_subdirectory(sandbox)

set(CMAKE_COLOR_MAKEFILE   ON)
