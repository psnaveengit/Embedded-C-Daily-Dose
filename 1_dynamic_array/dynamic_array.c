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

/**
 * Resize the array to new capacity
 * Returns: 0 on success, -1 on failure
 */
int dynamic_array_resize(DynamicArray *arr, size_t new_capacity) {
    if (arr == NULL || new_capacity < arr->size) {
        return -1;
    }
    
    int *new_data = (int*)realloc(arr->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        return -1;
    }
    
    arr->data = new_data;
    arr->capacity = new_capacity;
    return 0;
}

/**
 * Add element to end of array
 * Automatically resizes if needed
 */
int dynamic_array_push(DynamicArray *arr, int value) {
    if (arr == NULL) return -1;
    
    // resize if we're at capacity
    if (arr->size >= arr->capacity) {
        size_t new_cap = arr->capacity * 2;
        if (dynamic_array_resize(arr, new_cap) != 0) {
            return -1;
        }
    }
    
    arr->data[arr->size++] = value;
    return 0;
}

/**
 * Remove and return last element
 */
int dynamic_array_pop(DynamicArray *arr, int *value) {
    if (arr == NULL || arr->size == 0) {
        return -1;
    }
    
    if (value != NULL) {
        *value = arr->data[arr->size - 1];
    }
    arr->size--;
    
    // shrink if using less than 1/4 capacity
    if (arr->size > 0 && arr->size < arr->capacity / 4) {
        size_t new_cap = arr->capacity / 2;
        if (new_cap < INITIAL_CAPACITY) new_cap = INITIAL_CAPACITY;
        dynamic_array_resize(arr, new_cap); // ignore errors here
    }
    
    return 0;
}

/**
 * Get element at specific index
 */
int dynamic_array_get(DynamicArray *arr, size_t index, int *value) {
    if (arr == NULL || index >= arr->size || value == NULL) {
        return -1;
    }
    
    *value = arr->data[index];
    return 0;
}

/**
 * Set element at index
 */
int dynamic_array_set(DynamicArray *arr, size_t index, int value) {
    if (arr == NULL || index >= arr->size) {
        return -1;
    }
    arr->data[index] = value;
    return 0;
}

// Print array contents (for debugging)
void dynamic_array_print(DynamicArray *arr) {
    if (arr == NULL) return;
    
    printf("Array [size=%zu, cap=%zu]: [", arr->size, arr->capacity);
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("]\n");
}

/**
 * Free array memory
 */
void dynamic_array_free(DynamicArray *arr) {
    if (arr != NULL) {
        if (arr->data != NULL) {
            free(arr->data);
        }
        free(arr);
    }
}

// TODO: maybe add insert/delete at index functions later

/**
 * Test function - Complete functionality test
 */
int main(void) {
    printf("Dynamic Array - Complete Implementation\n");
    printf("========================================\n\n");
    
    DynamicArray *arr = dynamic_array_init();
    if (arr == NULL) {
        printf("Failed to initialize array\n");
        return 1;
    }
    
    printf("Array initialized successfully!\n");
    printf("Initial size: %zu, capacity: %zu\n\n", 
           dynamic_array_size(arr), dynamic_array_capacity(arr));
    
    // Test push operations
    printf("Testing push operations...\n");
    for (int i = 1; i <= 10; i++) {
        dynamic_array_push(arr, i * 10);
    }
    dynamic_array_print(arr);
    
    // Test get operation
    int val;
    if (dynamic_array_get(arr, 5, &val) == 0) {
        printf("Element at index 5: %d\n\n", val);
    }
    
    // Test pop operations
    printf("Testing pop operations...\n");
    for (int i = 0; i < 3; i++) {
        if (dynamic_array_pop(arr, &val) == 0) {
            printf("Popped: %d\n", val);
        }
    }
    dynamic_array_print(arr);
    
    // Test set operation
    printf("\nSetting index 2 to 999...\n");
    dynamic_array_set(arr, 2, 999);
    dynamic_array_print(arr);
    
    printf("\nAll operations completed successfully!\n");
    
    // Cleanup
    dynamic_array_free(arr);
    return 0;
}
