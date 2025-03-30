cmake_minimum_required(VERSION 3.29)
project(dsa C)

set(CMAKE_C_STANDARD 23)

add_subdirectory(dynamic_array)

add_subdirectory(ds_test_lib)

add_executable(dsa main.c)

target_link_libraries(dsa dynamic_array_lib)

target_link_libraries(dsa ds_test_lib)

enable_testing()