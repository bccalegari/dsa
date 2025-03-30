add_library(ds_test_lib STATIC ds_test.c)

target_include_directories(ds_test_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})