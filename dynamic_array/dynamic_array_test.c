#include "dynamic_array.h"

#include "../ds_test_lib/ds_test.h"

void should_get_size_dynamic_array() {
    DynamicArray* dy = dy_create();
    assert_equal(dy_size(dy), 0);
    dy_insert(dy, 2);
    assert_equal(dy_size(dy), 1);
    dy_insert(dy, 3);
    assert_equal(dy_size(dy), 2);
    dy_destroy(dy);
}

void should_insert_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    assert_equal(dy->size, 1);
    assert_equal(dy->data[0], 2);
    dy_destroy(dy);
}

void should_insert_at_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 3);
    dy_insert(dy, 4);
    dy_insert_at(dy, 5, 1);
    assert_equal(dy->size, 4);
    assert_equal(dy->data[1], 5);
    assert_equal(dy->data[2], 3);
    dy_destroy(dy);
}

void should_remove_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 3);
    dy_insert(dy, 4);
    dy_remove(dy);
    assert_equal(dy->size, 2);
    assert_equal(dy->data[1], 3);
    dy_destroy(dy);
}

void should_remove_at_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 3);
    dy_insert(dy, 4);
    dy_insert(dy, 5);
    dy_remove_at(dy, 1);
    assert_equal(dy->size, 3);
    assert_equal(dy->data[1], 4);
    assert_equal(dy->data[2], 5);
    dy_destroy(dy);
}

void should_get_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 3);
    dy_insert(dy, 4);
    assert_equal(dy_get(dy, 1), 3);
    dy_destroy(dy);
}

void should_search_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 3);
    dy_insert(dy, 4);
    assert_equal(dy_search(dy, 3), 1);
    dy_destroy(dy);
}

void should_search_and_not_find_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 3);
    dy_insert(dy, 4);
    assert_equal(dy_search(dy, 5), -1);
    dy_destroy(dy);
}

void should_contains_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 3);
    dy_insert(dy, 4);
    assert_true(dy_contains(dy, 3));
    dy_destroy(dy);
}

void should_not_contains_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 3);
    dy_insert(dy, 4);
    assert_false(dy_contains(dy, 5));
    dy_destroy(dy);
}

void should_sort_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 3);
    dy_insert(dy, 4);
    dy_insert(dy, 1);
    dy_sort(dy, 0);
    assert_equal(dy->data[0], 1);
    assert_equal(dy->data[1], 2);
    assert_equal(dy->data[2], 3);
    assert_equal(dy->data[3], 4);
    dy_destroy(dy);
}

void should_reverse_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 3);
    dy_insert(dy, 4);
    dy_insert(dy, 1);
    dy_reverse(dy);
    assert_equal(dy->data[0], 1);
    assert_equal(dy->data[1], 4);
    assert_equal(dy->data[2], 3);
    assert_equal(dy->data[3], 2);
    dy_destroy(dy);
}

void increment(int* data) {
    *data += 1;
}

void should_foreach_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 3);
    dy_insert(dy, 4);
    dy_insert(dy, 1);
    dy_foreach(dy, &increment);
    assert_equal(dy->data[0], 3);
    assert_equal(dy->data[1], 4);
    assert_equal(dy->data[2], 5);
    assert_equal(dy->data[3], 2);
    dy_destroy(dy);
}

void should_clear_dynamic_array() {
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 3);
    dy_insert(dy, 4);
    dy_insert(dy, 1);
    dy_clear(dy);
    assert_equal(dy->size, 0);
    dy_destroy(dy);
}

int main(void)
{
    register_test(should_get_size_dynamic_array, "should_get_size_dynamic_array");
    register_test(should_insert_dynamic_array, "should_insert_dynamic_array");
    register_test(should_insert_at_dynamic_array, "should_insert_at_dynamic_array");
    register_test(should_remove_dynamic_array, "should_remove_dynamic_array");
    register_test(should_remove_at_dynamic_array, "should_remove_at_dynamic_array");
    register_test(should_get_dynamic_array, "should_get_dynamic_array");
    register_test(should_search_dynamic_array, "should_search_dynamic_array");
    register_test(should_search_and_not_find_dynamic_array, "should_search_and_not_find_dynamic_array");
    register_test(should_contains_dynamic_array, "should_contains_dynamic_array");
    register_test(should_not_contains_dynamic_array, "should_not_contains_dynamic_array");
    register_test(should_sort_dynamic_array, "should_sort_dynamic_array");
    register_test(should_reverse_dynamic_array, "should_reverse_dynamic_array");
    register_test(should_foreach_dynamic_array, "should_foreach_dynamic_array");
    register_test(should_clear_dynamic_array, "should_clear_dynamic_array");
    run_tests();
    return 0;
}
