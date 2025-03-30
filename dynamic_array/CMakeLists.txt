add_library(dynamic_array_lib STATIC dynamic_array.c)

target_include_directories(dynamic_array_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(dynamic_array_test dynamic_array_test.c)

target_link_libraries(dynamic_array_test dynamic_array_lib)

add_test(NAME dynamic_array_test COMMAND dynamic_array_test)
