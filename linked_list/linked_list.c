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

int ll_remove_at_head(LinkedList* ll) {
    if (ll->head == NULL && ll->size == 0) {
        handle_error(ERROR_INVALID_INPUT, __FILE_NAME__, __LINE__, __func__);
        exit(EXIT_FAILURE);
    }

    Node* head = ll->head;

    if (ll->size == 1) {
        ll->head = NULL;
        ll->tail = NULL;
        ll->size--;
        return head->data;
    }

    Node* new_head = head->next;
    ll->head = new_head;
    ll->size--;

    return head->data;
}

int ll_remove_at_tail(LinkedList* ll) {
    if (ll->head == NULL && ll->size == 0) {
        handle_error(ERROR_INVALID_INPUT, __FILE_NAME__, __LINE__, __func__);
        exit(EXIT_FAILURE);
    }

    Node* tail = ll->tail;
    int tail_data = tail->data;

    if (ll->size == 1) {
        ll->head = NULL;
        ll->tail = NULL;
        ll->size--;
        free(tail);
        return tail_data;
    }

    Node* current = ll->head;

    while (current->next != tail) {
        current = current->next;
    }

    current->next = NULL;
    ll->tail = current;
    ll->size--;

    free(tail);
    return tail_data;
}

int ll_remove_at(LinkedList* ll, int index) {
    if (ll->head == NULL && ll->size == 0) {
        handle_error(ERROR_INVALID_INPUT, __FILE_NAME__, __LINE__, __func__);
        exit(EXIT_FAILURE);
    }

    if (index == 0) {
        return ll_remove_at_head(ll);
    }

    if (index == ll->size) {
        return ll_remove_at_tail(ll);
    }

    Node* current = ll->head;

    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node* to_remove = current->next;
    int to_remove_data = to_remove->data;
    current->next = to_remove->next;
    free(to_remove);
    ll->size--;

    return to_remove_data;
}
