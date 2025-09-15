#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    size_t size;
    size_t capacity;
    int* data;
} vector;

vector* createVector() {
    int initial_size = 4;
    vector* arr = malloc(sizeof(vector));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    arr->data = malloc(initial_size * sizeof(int));
    if (!arr->data) {
        free(arr);
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    arr->size = 0;
    arr->capacity = initial_size;
    return arr;
}

int freeArray(vector** arr) { 
    if (!arr || !*arr) {
        fprintf(stderr, "Array is NULL\n");
        return -1;
    }
    free((*arr)->data);
    free(*arr);
    *arr = NULL;  
    return 1;
}

int autoResizeArray(vector* arr) {
    if (!arr) {
        fprintf(stderr, "Array is NULL\n");
        return -1;
    }
    int* newData = realloc(arr->data, arr->capacity * 2 * sizeof(int));
    if (!newData) {
        fprintf(stderr, "Memory reallocation failed\n");
        return -1;
    }
    arr->data = newData;
    arr->capacity *= 2;
    return 1;
}

int pushBack(vector* arr, int value) {
    if (!arr) {
        fprintf(stderr, "Array is NULL\n");
        return -1;
    }
    if (arr->size >= arr->capacity) {
        if (autoResizeArray(arr) == -1) {
            return -1;
        }
    }
    arr->data[arr->size] = value;
    arr->size++;
    return 1;
}

int printArray(vector* arr) {
    if (!arr) {
        fprintf(stderr, "Array is NULL\n");
        return -1;
    }
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
    return 1;
}

int popBack(vector* arr) {
    if (!arr) {
        fprintf(stderr, "Array is NULL\n");
        return -1;
    }
    if (arr->size == 0) {
        fprintf(stderr, "Array is empty\n");
        return -1;
    }
    arr->size--;
    return 1;
}

size_t getSize(vector* arr) {
    if (!arr) {
        return 0;
    }
    return arr->size;
}

int insertByIndex(vector* arr, int index, int val) {
    if (!arr) {
        fprintf(stderr, "Vector is NULL\n");
        return -1;
    }
    if (index < 0 || index > arr->size) { 
        fprintf(stderr, "Index out of bounds\n");
        return -1;
    }
    
    if (arr->size >= arr->capacity) {
        if (autoResizeArray(arr) == -1) {
            return -1;
        }
    }
    
    for (int i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = val;
    arr->size++;
    return 1;
}

int removeByIndex(vector* arr, int index) {
    if (!arr) {
        fprintf(stderr, "Array is NULL\n");
        return -1;
    }
    if (index < 0 || index >= arr->size) {
        fprintf(stderr, "Index out of bounds\n");
        return -1;
    }
    
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
    return 1;
}