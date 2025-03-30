#include "dynamic_array.h"

#include <stdio.h>

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
    printf("%d\n", dy->data[0]);
    printf("%zu\n", dy->size);
    printf("%d\n", dy->capacity);
    printf("%d\n", dy_remove(dy));
    printf("%zu\n", dy->size);
    dy_destroy(dy);
    return 0;
}
