#include "linked_list.h"

#include <stdio.h>

typedef enum {
    ERROR_MEMORY_ALLOCATION,
    ERROR_INVALID_INPUT,
    ERROR_INDEX_OUT_OF_BOUNDS
} ErrorType;

char* error_messages[] = {
    "Memory allocation failed",
    "Invalid input provided",
    "Index out of bounds"
};

void handle_error(ErrorType error_type, char* file, int line, char* func) {
    fprintf(stderr, "ERROR (%s:%d) - %s: %s", file, line, func, error_messages[error_type]);
}

Node* ll_create_node(int data) {
    Node* node = malloc(sizeof(Node));

    if (node == NULL) {
        handle_error(ERROR_MEMORY_ALLOCATION, __FILE_NAME__, __LINE__, __func__);
        exit(EXIT_FAILURE);
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void ll_destroy_node(Node* node) {
    if (node != NULL) {
        free(node);
    }
}

LinkedList* ll_create() {
    LinkedList* linked_list = malloc(sizeof(LinkedList));

    if (linked_list == NULL) {
        handle_error(ERROR_MEMORY_ALLOCATION, __FILE_NAME__, __LINE__, __func__);
        exit(EXIT_FAILURE);
    }

    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->size = 0;

    return linked_list;
}

void ll_destroy(LinkedList* ll) {
    if (ll != NULL) {
        Node* current = ll->head;

        while (current != NULL) {
            Node* next = current->next;
            ll_destroy_node(current);
            current = next;
        }

        free(ll);
    }
}

size_t ll_size(LinkedList* ll) {
    return ll->size;
}

void ll_insert_at_head(LinkedList* ll, int data) {
    Node* new_node = ll_create_node(data);

    if (ll->head == NULL && ll->size == 0) {
        ll->head = new_node;
        ll->tail = new_node;
        ll->size++;
        return;
    }

    Node* current = ll->head;
    ll->head = new_node;
    ll->head->next = current;
    ll->size++;
}

void ll_insert_at_tail(LinkedList* ll, int data) {
    Node* new_node = ll_create_node(data);

    if (ll->head == NULL && ll->size == 0) {
        ll_insert_at_head(ll, data);
        return;
    }

    Node* current = ll->tail;
    ll->tail = new_node;
    current->next = new_node;
    ll->size++;
}

void ll_insert_at(LinkedList* ll, int data, int index) {
    if (index > ll->size || index < 0) {
        handle_error(ERROR_INDEX_OUT_OF_BOUNDS, __FILE_NAME__, __LINE__, __func__);
        return;
    }

    if (index == 0) {
        ll_insert_at_head(ll, data);
        return;
    }

    if (index == ll->size) {
        ll_insert_at_tail(ll, data);
        return;
    }

    Node* new_node = ll_create_node(data);
    Node* current = ll->head;

    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    ll->size++;
}
