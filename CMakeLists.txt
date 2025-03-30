cmake_minimum_required(VERSION 3.29)
project(dsa C)

set(CMAKE_C_STANDARD 23)

enable_testing()

add_subdirectory(dynamic_array)

add_executable(dsa main.c)

target_link_libraries(dsa dynamic_array_lib)