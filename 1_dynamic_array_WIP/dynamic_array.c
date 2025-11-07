/**
 * Dynamic Array Implementation - Day 1 (Part 1/2)
 * A resizable array data structure for embedded systems
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 4

/**
 * Dynamic Array Structure
 * Manages a resizable array with automatic memory management
 */
typedef struct {
    int *data;           // Pointer to array elements
    size_t size;         // Current number of elements
    size_t capacity;     // Total allocated capacity
} DynamicArray;

/**
 * Initialize a new dynamic array
 * Returns: Pointer to initialized array, or NULL on failure
 */
DynamicArray* dynamic_array_init(void) {
    DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (arr == NULL) {
        return NULL;
    }
    
    arr->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (arr->data == NULL) {
        free(arr);
        return NULL;
    }
    
    arr->size = 0;
    arr->capacity = INITIAL_CAPACITY;
    
    return arr;
}

/**
 * Get current size of the array
 */
size_t dynamic_array_size(DynamicArray *arr) {
    return arr ? arr->size : 0;
}

/**
 * Get current capacity of the array
 */
size_t dynamic_array_capacity(DynamicArray *arr) {
    return arr ? arr->capacity : 0;
}

// TODO - Day 2: Implement resize function
// int dynamic_array_resize(DynamicArray *arr, size_t new_capacity);

// TODO - Day 2: Implement add/push function
// int dynamic_array_push(DynamicArray *arr, int value);

// TODO - Day 2: Implement remove/pop function
// int dynamic_array_pop(DynamicArray *arr, int *value);

// TODO - Day 2: Implement get element at index
// int dynamic_array_get(DynamicArray *arr, size_t index, int *value);

// TODO - Day 2: Implement free/destroy function
// void dynamic_array_free(DynamicArray *arr);

/**
 * Test function - Basic initialization test
 */
int main(void) {
    printf("Dynamic Array - Day 1 Test\n");
    printf("==========================\n\n");
    
    DynamicArray *arr = dynamic_array_init();
    if (arr == NULL) {
        printf("Failed to initialize array\n");
        return 1;
    }
    
    printf("Array initialized successfully!\n");
    printf("Initial size: %zu\n", dynamic_array_size(arr));
    printf("Initial capacity: %zu\n", dynamic_array_capacity(arr));
    
    printf("\nDay 2 will implement: add, remove, resize operations\n");
    
    // Note: Memory cleanup will be implemented in Day 2
    return 0;
}
