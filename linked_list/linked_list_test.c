#include "linked_list.h"

#include <stdio.h>

#include "../ds_test_lib/ds_test.h"

void should_insert_at_head_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    assert_equal(1, ll->size);
    assert_equal(2, ll->head->data);
    assert_equal(2, ll->tail->data);
    ll_destroy(ll);
}

void should_insert_at_tail_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 8);
    ll_insert_at_tail(ll, 2);
    assert_equal(2, ll->size);
    assert_equal(8, ll->head->data);
    assert_equal(2, ll->tail->data);
    assert_equal(2, ll->head->next->data);
    ll_destroy(ll);
}

void should_insert_at_head_with_index_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at(ll, 9, 0);
    assert_equal(1, ll->size);
    assert_equal(9, ll->head->data);
    ll_insert_at(ll, 2, 0);
    assert_equal(2, ll->size);
    assert_equal(2, ll->head->data);
    assert_equal(9, ll->head->next->data);
    ll_destroy(ll);
}

void should_insert_at_tail_with_index_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at(ll, 9, 0);
    assert_equal(1, ll->size);
    assert_equal(9, ll->head->data);
    ll_insert_at(ll, 2, 1);
    assert_equal(2, ll->size);
    assert_equal(2, ll->tail->data);
    assert_equal(9, ll->head->data);
    assert_equal(2, ll->head->next->data);
    ll_insert_at(ll, 3, 2);
    assert_equal(3, ll->size);
    assert_equal(3, ll->tail->data);
    ll_destroy(ll);
}

void should_insert_at_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_tail(ll, 2);
    ll_insert_at_tail(ll, 3);
    ll_insert_at_tail(ll, 4);
    ll_insert_at(ll, 9, 1);
    assert_equal(4, ll->size);
    assert_equal(2, ll->head->data);
    assert_equal(9, ll->head->next->data);
    assert_equal(3, ll->head->next->next->data);
    assert_equal(4, ll->head->next->next->next->data);
    ll_destroy(ll);
}

void should_remove_at_head_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    assert_equal(2, ll_remove_at_head(ll));
    assert_equal(0, ll->size);
    assert_null(ll->head);
    assert_null(ll->tail);
    ll_insert_at_head(ll, 2);
    ll_insert_at_head(ll, 3);
    assert_equal(3, ll_remove_at_head(ll));
    assert_equal(1, ll->size);
    assert_not_null(ll->head);
    assert_not_null(ll->tail);
    assert_equal(2, ll_remove_at_head(ll));
    assert_equal(0, ll->size);
    assert_null(ll->head);
    assert_null(ll->tail);
    ll_destroy(ll);
}

void should_remove_at_tail_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    assert_equal(2, ll_remove_at_tail(ll));
    assert_equal(0, ll->size);
    assert_null(ll->head);
    assert_null(ll->tail);
    ll_insert_at_head(ll, 2);
    ll_insert_at_tail(ll, 3);
    assert_equal(3, ll_remove_at_tail(ll));
    assert_equal(1, ll->size);
    assert_not_null(ll->head);
    assert_not_null(ll->tail);
    assert_equal(2, ll_remove_at_tail(ll));
    assert_equal(0, ll->size);
    assert_null(ll->head);
    assert_null(ll->tail);
    ll_destroy(ll);
}

void should_remove_at_head_index_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    assert_equal(2, ll_remove_at(ll, 0));
    assert_equal(0, ll->size);
    assert_null(ll->head);
    assert_null(ll->tail);
    ll_insert_at_head(ll, 2);
    ll_insert_at_head(ll, 3);
    assert_equal(3, ll_remove_at(ll, 0));
    assert_equal(1, ll->size);
    assert_not_null(ll->head);
    assert_not_null(ll->tail);
    assert_equal(2, ll_remove_at(ll, 0));
    assert_equal(0, ll->size);
    assert_null(ll->head);
    assert_null(ll->tail);
    ll_destroy(ll);
}

void should_remove_at_tail_index_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    assert_equal(2, ll_remove_at(ll, 0));
    assert_equal(0, ll->size);
    assert_null(ll->head);
    assert_null(ll->tail);
    ll_insert_at_head(ll, 2);
    ll_insert_at_tail(ll, 3);
    assert_equal(3, ll_remove_at(ll, 1));
    assert_equal(1, ll->size);
    assert_not_null(ll->head);
    assert_not_null(ll->tail);
    assert_equal(2, ll_remove_at(ll, 0));
    assert_equal(0, ll->size);
    assert_null(ll->head);
    assert_null(ll->tail);
    ll_destroy(ll);
}

void should_remove_at_index_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    ll_insert_at_tail(ll, 3);
    ll_insert_at_tail(ll, 4);
    assert_equal(3, ll_remove_at(ll, 1));
    assert_equal(2, ll->head->data);
    assert_equal(4, ll->head->next->data);
    assert_equal(2, ll->size);
    assert_equal(4, ll->tail->data);
    assert_null(ll->tail->next);
    ll_destroy(ll);
}

void should_get_head_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    assert_equal(2, ll_get_head(ll));
    assert_equal(1, ll->size);
    ll_destroy(ll);
}

void should_get_tail_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    ll_insert_at_tail(ll, 7);
    assert_equal(7, ll_get_tail(ll));
    assert_equal(2, ll->head->data);
    ll_destroy(ll);
}

void should_get_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    ll_insert_at_tail(ll, 7);
    ll_insert_at_tail(ll, 4);
    assert_equal(2, ll_get(ll, 0));
    assert_equal(7, ll_get(ll, 1));
    assert_equal(4, ll_get(ll, 2));
    assert_equal(3, ll->size);
    ll_destroy(ll);
}

void should_search_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    ll_insert_at_tail(ll, 7);
    ll_insert_at_tail(ll, 4);
    assert_equal(0, ll_search(ll, 2));
    assert_equal(1, ll_search(ll, 7));
    assert_equal(2, ll_search(ll, 4));
    assert_equal(-1, ll_search(ll, 5));
    assert_equal(-1, ll_search(ll, 8));
    assert_equal(-1, ll_search(ll, 9));
    assert_equal(3, ll->size);
    ll_destroy(ll);
}

void should_contain_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    ll_insert_at_tail(ll, 7);
    ll_insert_at_tail(ll, 4);
    assert_true(ll_contains(ll, 2));
    assert_true(ll_contains(ll, 7));
    assert_true(ll_contains(ll, 4));
    assert_false(ll_contains(ll, 5));
    assert_false(ll_contains(ll, 8));
    assert_false(ll_contains(ll, 9));
    assert_equal(3, ll->size);
    ll_destroy(ll);
}

void should_sort_ascending_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    ll_insert_at_tail(ll, 7);
    ll_insert_at_tail(ll, 4);
    ll_sort(ll, 0);
    assert_equal(2, ll_get(ll, 0));
    assert_equal(4, ll_get(ll, 1));
    assert_equal(7, ll_get(ll, 2));
    assert_equal(3, ll->size);
    ll_destroy(ll);
}

void should_sort_descending_linked_list() {
    LinkedList* ll = ll_create();
    ll_insert_at_head(ll, 2);
    ll_insert_at_tail(ll, 7);
    ll_insert_at_tail(ll, 4);
    ll_sort(ll, 1);
    assert_equal(7, ll_get(ll, 0));
    assert_equal(4, ll_get(ll, 1));
    assert_equal(2, ll_get(ll, 2));
    assert_equal(3, ll->size);
    ll_destroy(ll);
}

int main(void)
{
    register_test(should_insert_at_head_linked_list, "should_insert_at_head_linked_list");
    register_test(should_insert_at_tail_linked_list, "should_insert_at_tail_linked_list");
    register_test(should_insert_at_head_with_index_linked_list, "should_insert_at_head_with_index_linked_list");
    register_test(should_insert_at_tail_with_index_linked_list, "should_insert_at_tail_with_index_linked_list");
    register_test(should_insert_at_linked_list, "should_insert_at_linked_list");
    register_test(should_remove_at_head_linked_list, "should_remove_at_head_linked_list");
    register_test(should_remove_at_tail_linked_list, "should_remove_at_tail_linked_list");
    register_test(should_remove_at_head_index_linked_list, "should_remove_at_head_index_linked_list");
    register_test(should_remove_at_tail_index_linked_list, "should_remove_at_tail_index_linked_list");
    register_test(should_remove_at_index_linked_list, "should_remove_at_index_linked_list");
    register_test(should_get_head_linked_list, "should_get_head_linked_list");
    register_test(should_get_tail_linked_list, "should_get_tail_linked_list");
    register_test(should_get_linked_list, "should_get_linked_list");
    register_test(should_search_linked_list, "should_search_linked_list");
    register_test(should_contain_linked_list, "should_contain_linked_list");
    register_test(should_sort_ascending_linked_list, "should_sort_ascending_linked_list");
    register_test(should_sort_descending_linked_list, "should_sort_descending_linked_list");
    run_tests();
    return 0;
}
