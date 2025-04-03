#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int capacity;
    size_t size;
} DynamicArray;

DynamicArray* dy_create();
void dy_destroy(DynamicArray* dy);
size_t dy_size(DynamicArray* dy);
void dy_insert(DynamicArray* dy, int data);
void dy_insert_at(DynamicArray* dy, int data, int index);
int dy_remove(DynamicArray* dy);
int dy_remove_at(DynamicArray* dy, int index);
int dy_get(DynamicArray* dy, int index);
int dy_search(DynamicArray* dy, int data);
bool dy_contains(DynamicArray* dy, int data);
void dy_sort(DynamicArray* dy, int mode);
void dy_reverse(DynamicArray* dy);
void dy_foreach(DynamicArray* dy, void (*fn)(int*));
void dy_clear(DynamicArray* dy);
void dy_print(DynamicArray* dy);
void dy_print_data(DynamicArray* dy);

#endif