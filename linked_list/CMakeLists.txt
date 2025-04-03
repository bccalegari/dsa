add_library(linked_list_lib STATIC linked_list.c)

target_include_directories(linked_list_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(linked_list_test linked_list_test.c)

target_link_libraries(linked_list_test linked_list_lib)

target_link_libraries(linked_list_test ds_test_lib)

add_test(NAME linked_list_test COMMAND linked_list_test)
