#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "vector.h"

#define DEFAULT_CAPACITY (1)

struct Vector {
    int* array;
    int length;
    int capacity;
};

int size(Vector* vector) {
    return vector->length;
}

int capacity(Vector* vector) {
    return vector->capacity;
}

int is_empty(Vector* vector) {
    return size(vector) <= 0;
}

Vector* new_vector() {
    Vector* out = malloc(sizeof(Vector));

    out->array = malloc(sizeof(int) * DEFAULT_CAPACITY);
    out->length = 0;
    out->capacity = DEFAULT_CAPACITY;

    return out;
}

void resize(Vector* vector, int new_capacity) {
    int* new_arr = realloc(vector->array, sizeof(int) * new_capacity);

    vector->array = new_arr;
    vector->capacity = new_capacity;
}

void check_index(Vector* vector, int index) {
    //fail if array if out of bounds
    if (index >= size(vector)) {
        printf("Index %d out of bounds for vector of size %d\n", index, size(vector));
        exit(-1);
    }
}

void resize_if_full(Vector* vector) {
    if (size(vector) >= capacity(vector)) {
        resize(vector, capacity(vector) << 1);
    }
}

void resize_if_quarter(Vector* vector) {
    if (capacity(vector) > DEFAULT_CAPACITY && size(vector) <= capacity(vector) >> 2) {
        resize(vector, capacity(vector) >> 1);
    }
}

void push(Vector* vector, int item) {
    resize_if_full(vector);

    *(vector->array + size(vector)) = item;

    vector->length++;
}

void insert(Vector* vector, int index, int item) {
    check_index(vector, index - 1);
    resize_if_full(vector);

    memcpy(vector->array + index + 1, vector->array + index, sizeof(int) * (size(vector) - index));

    *(vector->array + index) = item;

    vector->length++;
}

void prepend(Vector* vector, int item) {
    insert(vector, 0, item);
}

void delete_at(Vector* vector, int index) {
    check_index(vector, index);

    memcpy(vector->array + index, vector->array + index + 1 , sizeof(int) * (size(vector) - index));

    vector->length--;

    resize_if_quarter(vector);
}

int at(Vector* vector, int index) {
    check_index(vector, index);
    return *(vector->array + index);
}

void remove_all(Vector* vector, int item) {
    for (int i = 0; i < size(vector); i++) {
        if (at(vector, i) == item) {
            delete_at(vector, i);
            i--;
        }
    }
}

int pop(Vector* vector) {
    if (size(vector) <= 0) exit(1);

    vector->length--;

    resize_if_quarter(vector);
}

int find(Vector* vector, int item) {
    for (int i = 0; i < size(vector); i++) {
        if (at(vector, i) == item) {
            return i;
        }
    }

    return -1;
}

void print(Vector* vector) {
    printf("[");

    for (int i = 0; i < size(vector) - 1; i++) {
        printf("%d, ", at(vector, i));
    }

    if (size(vector) > 0) {
        printf("%d]", at(vector, size(vector) - 1));
    }
    else {
        printf("]");
    }

    printf(" length=%d capacity=%d", size(vector), capacity(vector));

    printf("\n");
}

void delete(Vector* vector) {
    free(vector->array);
    free(vector);
}