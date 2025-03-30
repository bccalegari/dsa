#include "dynamic_array.h"

#include <stdio.h>

typedef enum {
    ERROR_MEMORY_ALLOCATION,
    ERROR_INVALID_INPUT
} ErrorType;

const char* error_messages[] = {
    "Memory allocation failed",
    "Invalid input provided"
};

void handle_error(const ErrorType error_type, const char* file, const int line, const char* func) {
    fprintf(stderr, "ERROR (%s:%d) - %s: %s", file, line, func, error_messages[error_type]);
}

bool dy_is_half_max_length(const DynamicArray* dy) {
    return dy->size >= dy->capacity / 2;
}

void resize_dy(DynamicArray* dy) {
    dy->capacity = dy->capacity * 2;
    dy->data = realloc(dy->data, sizeof(int*) * dy->capacity);

    if (dy->data == NULL) {
        free(dy->data);
        free(dy);
        handle_error(ERROR_MEMORY_ALLOCATION, __FILE_NAME__, __LINE__, __func__);
        exit(EXIT_FAILURE);
    }
}

DynamicArray* dy_create() {
    DynamicArray* dy = malloc(sizeof(DynamicArray*));

    if (dy == NULL) {
        handle_error(ERROR_MEMORY_ALLOCATION, __FILE_NAME__, __LINE__, __func__);
        exit(1);
    }

    dy->size = 0;
    dy->capacity = 16;
    dy->data = malloc(sizeof(int*) * dy->capacity);

    if (dy->data == NULL) {
        handle_error(ERROR_MEMORY_ALLOCATION, __FILE_NAME__, __LINE__, __func__);
        free(dy);
        exit(1);
    }

    return dy;
}

void dy_destroy(DynamicArray* dy) {
    if (dy != NULL) {
        free(dy->data);
        free(dy);
    }
}

void dy_insert(DynamicArray* dy, const int data) {
    if (dy_is_half_max_length(dy)) {
        resize_dy(dy);
    }

    dy->data[dy->size++] = data;
}

int dy_remove(DynamicArray* dy) {
    if (dy->size <= 0) {
        handle_error(ERROR_INVALID_INPUT, __FILE_NAME__, __LINE__, __func__);
        exit(1);
    }

    const int value = dy->data[dy->size - 1];
    dy->size--;
    return value;
}