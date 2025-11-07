# Dynamic Array Implementation

## Overview
A dynamic array (also known as a resizable array or vector) is a data structure that provides automatic resizing capabilities. Unlike static arrays in C, dynamic arrays can grow or shrink as needed during runtime, making them essential for embedded systems where memory efficiency and flexibility are crucial.

## Status
**In Progress - Part 1/2**

This is Day 1 of a two-day implementation cycle.

## What's Implemented (Day 1)

✅ **Basic Structure**
- `DynamicArray` struct with data pointer, size, and capacity tracking
- Memory-safe design suitable for embedded systems

✅ **Initialization Function**
- `dynamic_array_init()` - Creates and initializes a new dynamic array
- Proper error handling for memory allocation failures
- Initial capacity set to 4 elements

✅ **Query Functions**
- `dynamic_array_size()` - Returns current number of elements
- `dynamic_array_capacity()` - Returns total allocated capacity

## Coming in Part 2 (Day 2)

🔄 **Core Operations** (To be implemented tomorrow)
- `dynamic_array_resize()` - Resize internal buffer when needed
- `dynamic_array_push()` - Add elements to the array
- `dynamic_array_pop()` - Remove elements from the array
- `dynamic_array_get()` - Access elements by index
- `dynamic_array_free()` - Clean up and free memory

## Compilation
```bash
gcc -o dynamic_array dynamic_array.c
./dynamic_array
```

## Project Structure
```
1_dynamic_array_WIP/
├── dynamic_array.c    # Main implementation (partial)
└── README.md          # This file
```

## Learning Objectives
- Understanding dynamic memory allocation in C
- Implementing resizable data structures
- Memory management best practices for embedded systems
- Handling edge cases and error conditions

---
*Part of the Embedded-C-Daily-Dose learning journey*
