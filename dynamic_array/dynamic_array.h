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
size_t dy_size(const DynamicArray* dy);
void dy_insert(DynamicArray* dy, int data);
void dy_insert_at(DynamicArray* dy, int data, int index);
int dy_remove(DynamicArray* dy);
int dy_remove_at(DynamicArray* dy, int index);
int dy_get(const DynamicArray* dy, int index);
int dy_search(const DynamicArray* dy, int data);
bool dy_contains(const DynamicArray* dy, int data);
void dy_sort(const DynamicArray* dy, int mode);
void dy_reverse(const DynamicArray* dy);
void dy_foreach(const DynamicArray* dy, void (*fn)(int*));
void dy_clear(DynamicArray* dy);
void dy_print(const DynamicArray* dy);
void dy_print_data(const DynamicArray* dy);

#endif