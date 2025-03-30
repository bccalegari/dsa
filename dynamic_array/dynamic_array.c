#include "dynamic_array.h"

#include <stdio.h>

typedef enum {
    ERROR_MEMORY_ALLOCATION,
    ERROR_INVALID_INPUT,
    ERROR_INDEX_OUT_OF_BOUNDS
} ErrorType;

const char* error_messages[] = {
    "Memory allocation failed",
    "Invalid input provided",
    "Index out of bounds"
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

void dy_insert_at(DynamicArray* dy, const int data, const int index) {
    if (dy_is_half_max_length(dy)) {
        resize_dy(dy);
    }

    if (index > dy->size || index < 0) {
        handle_error(ERROR_INDEX_OUT_OF_BOUNDS, __FILE_NAME__, __LINE__, __func__);
    }

    for(int i = dy->size; i > index; i--) {
        dy->data[i] = dy->data[i-1];
    }

    dy->data[index] = data;
    dy->size++;
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

int dy_remove_at(DynamicArray* dy, const int index) {
    if (dy->size <= 0) {
        handle_error(ERROR_INVALID_INPUT, __FILE_NAME__, __LINE__, __func__);
        exit(1);
    }

    if (index >= dy->size || index < 0) {
        handle_error(ERROR_INDEX_OUT_OF_BOUNDS, __FILE_NAME__, __LINE__, __func__);
    }

    const int value = dy->data[index];

    for(int i = index; i < dy->size - 1; i++) {
        dy->data[i] = dy->data[i+1];
    }

    dy->size--;
    return value;
}

int dy_get(const DynamicArray* dy, const int index) {
    if (index >= dy->size || index < 0) {
        handle_error(ERROR_INDEX_OUT_OF_BOUNDS, __FILE_NAME__, __LINE__, __func__);
    }

    return dy->data[index];
}

int dy_search(const DynamicArray* dy, const int data) {
    for(int i = 0; i < dy->size - 1; i++) {
        if (dy->data[i] == data) {
            return i;
        }
    }

    return -1;
}

bool dy_contains(const DynamicArray* dy, const int data) {
    for(int i = 0; i < dy->size - 1; i++) {
        if (dy->data[i] == data) {
            return true;
        }
    }

    return false;
}

//Selection sort O(n^2)
void dy_sort(const DynamicArray* dy, const int mode) {
    switch (mode) {
        case 0:
            for(int i = 0; i < dy->size - 1; i++) {
                for(int j = i + 1; j < dy->size; j++) {
                    if (dy->data[j] < dy->data[i]) {
                        const int temp = dy->data[j];
                        dy->data[j] = dy->data[i];
                        dy->data[i] = temp;
                    }
                }
            }
            break;
        case 1:
            for(int i = 0; i < dy->size - 1; i++) {
                for(int j = i + 1; j < dy->size; j++) {
                    if (dy->data[j] > dy->data[i]) {
                        const int temp = dy->data[j];
                        dy->data[j] = dy->data[i];
                        dy->data[i] = temp;
                    }
                }
            }
            break;
        default:
            handle_error(ERROR_INVALID_INPUT, __FILE_NAME__, __LINE__, __func__);
    }
}

void dy_reverse(const DynamicArray* dy) {
    int* temp = malloc(sizeof(int) * dy->size);

    if (temp == NULL) {
        handle_error(ERROR_MEMORY_ALLOCATION, __FILE_NAME__, __LINE__, __func__);
        free(temp);
        exit(1);
    }

    int reverse_index = dy->size - 1;

    for(int i = 0; i <= dy->size - 1; i++) {
        temp[i] = dy->data[reverse_index];
        reverse_index--;
    }

    for(int i = 0; i <= dy->size - 1; i++) {
        dy->data[i] = temp[i];
    }

    free(temp);
}

void dy_foreach(const DynamicArray* dy, void (*fn)(int*)) {
    for(int i = 0; i <= dy->size - 1; i++) {
        fn(&dy->data[i]);
    }
}

void dy_clear(DynamicArray* dy) {
    dy->size = 0;
    dy->capacity = 8;
    dy->data = realloc(dy->data, sizeof(int*) * dy->capacity);

    if (dy->data == NULL) {
        free(dy->data);
        free(dy);
        handle_error(ERROR_MEMORY_ALLOCATION, __FILE_NAME__, __LINE__, __func__);
        exit(EXIT_FAILURE);
    }
}

void dy_print(const DynamicArray* dy) {
    printf("DynamicArray@%p {", dy);
    printf("size: %zu, capacity: %d, data@%p: [", dy->size, dy->capacity, dy->data);

    if (dy->size == 0) {
        printf("]}\n");
        return;
    }

    for (int i = 0; i < dy->size - 1; i++) {
        printf("%d, ", dy->data[i]);
    }
    printf("%d]}\n", dy->data[dy->size - 1]);
}

void dy_print_data(const DynamicArray* dy) {
    printf("DynamicArray_data@%p [", dy->data);

    if (dy->size == 0) {
        printf("]}\n");
        return;
    }

    for (int i = 0; i < dy->size - 1; i++) {
        printf("%d, ", dy->data[i]);
    }
    printf("%d]\n", dy->data[dy->size - 1]);
}