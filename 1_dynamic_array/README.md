# Dynamic Array Implementation

## Overview
A dynamic array (also known as a resizable array or vector) is a data structure that provides automatic resizing capabilities. Unlike static arrays in C, dynamic arrays can grow or shrink as needed during runtime, making them essential for embedded systems where memory efficiency and flexibility are crucial.

This implementation is complete and fully functional, providing all the core operations you'd need for a production-ready dynamic array in embedded C.

## Features

✅ **Complete Implementation**
- Automatic resizing when capacity is reached (doubles capacity)
- Smart shrinking when usage drops below 25% (halves capacity)
- Memory-safe design with proper error handling
- Suitable for resource-constrained embedded systems

## API Functions

### Initialization & Cleanup
- `dynamic_array_init()` - Creates and initializes a new dynamic array with initial capacity of 4
- `dynamic_array_free()` - Frees all allocated memory

### Core Operations
- `dynamic_array_push(arr, value)` - Add element to end of array (auto-resizes if needed)
- `dynamic_array_pop(arr, &value)` - Remove and return last element (auto-shrinks if needed)
- `dynamic_array_get(arr, index, &value)` - Get element at specific index
- `dynamic_array_set(arr, index, value)` - Set element at specific index

### Query Functions
- `dynamic_array_size(arr)` - Returns current number of elements
- `dynamic_array_capacity(arr)` - Returns total allocated capacity

### Utility
- `dynamic_array_print(arr)` - Print array contents for debugging
- `dynamic_array_resize(arr, new_capacity)` - Manually resize the array

## How It Works

The dynamic array starts with a small capacity (4 elements) and automatically grows when you add more elements. When you push an element and the array is full, it doubles its capacity. Similarly, when you pop elements and the array becomes less than 25% full, it shrinks to half its capacity to save memory.

This approach balances memory efficiency with performance - you don't waste too much space, but you also don't resize too frequently.

## Compilation & Usage

```bash
# Compile
gcc -o dynamic_array dynamic_array.c

# Run the test program
./dynamic_array
```

The test program demonstrates all the operations - pushing elements, popping them, getting/setting values, and shows how the capacity changes automatically.

## Example Output

```
Dynamic Array - Complete Implementation
========================================

Array initialized successfully!
Initial size: 0, capacity: 4

Testing push operations...
Array [size=10, cap=16]: [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
Element at index 5: 60

Testing pop operations...
Popped: 100
Popped: 90
Popped: 80
Array [size=7, cap=16]: [10, 20, 30, 40, 50, 60, 70]

Setting index 2 to 999...
Array [size=7, cap=16]: [10, 20, 999, 40, 50, 60, 70]

All operations completed successfully!
```

## Key Concepts

**Memory Management**: Uses `malloc()`, `realloc()`, and `free()` for dynamic memory allocation. Always checks for allocation failures.

**Amortized O(1) Push**: While individual pushes might trigger a resize (O(n)), the amortized cost over many operations is O(1) because we double the capacity each time.

**Space Efficiency**: Automatically shrinks when usage drops to avoid wasting memory, which is crucial in embedded systems.

## Future Enhancements

Could add insert/delete at arbitrary positions, but for most embedded use cases, push/pop operations are sufficient and more efficient.

---
*Part of the Embedded-C-Daily-Dose learning journey*
