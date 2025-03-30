#include "dynamic_array.h"

#include <stdio.h>

void sum1(int* value) {
    *value += 1;
}

int main(void)
{
    DynamicArray* dy = dy_create();
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_insert(dy, 2);
    dy_print(dy);
    printf("%d\n", dy_remove(dy));
    dy_print(dy);
    dy_destroy(dy);
    dy = dy_create();
    dy_print(dy);
    dy_insert(dy, 4);
    dy_insert(dy, 5);
    dy_insert(dy, 7);
    dy_insert(dy, 8);
    dy_insert(dy, 9);
    dy_insert_at(dy, 1, 2);
    dy_print(dy);
    dy_remove_at(dy, 5);
    dy_print(dy);
    dy_print_data(dy);
    dy_clear(dy);
    dy_insert(dy, 6);
    dy_insert(dy, 7);
    dy_insert(dy, 5);
    dy_insert(dy, 3);
    dy_print(dy);
    dy_sort(dy, 1);
    dy_print(dy);
    printf("reverse\n");
    dy_reverse(dy);
    dy_print(dy);
    printf("foreach\n");
    dy_foreach(dy, sum1);
    dy_print(dy);
    return 0;
}
