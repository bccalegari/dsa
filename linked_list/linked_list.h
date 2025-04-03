#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    size_t size;
} LinkedList;

Node* ll_create_node(int data);
void ll_destroy_node(Node* node);
LinkedList* ll_create();
void ll_destroy(LinkedList* ll);
size_t ll_size(LinkedList* ll);
void ll_insert_at_head(LinkedList* ll, int data);
void ll_insert_at_tail(LinkedList* ll, int data);
void ll_insert_at(LinkedList* ll, int data, int index);
int ll_remove_at_head(LinkedList* ll);
int ll_remove_at_tail(LinkedList* ll);
int ll_remove_at(LinkedList* ll, int index);
int ll_get_head(LinkedList* ll);
int ll_get_tail(LinkedList* ll);
int ll_get(LinkedList* ll, int index);
int ll_search(LinkedList* ll, int data);
bool ll_contains(LinkedList* ll, int data);
void ll_sort(LinkedList* ll, int mode);
void ll_reverse(LinkedList* ll);
void ll_foreach(LinkedList* ll, void (*fn)(int*));
void ll_clear(LinkedList* ll);
void ll_print(LinkedList* ll);

#endif