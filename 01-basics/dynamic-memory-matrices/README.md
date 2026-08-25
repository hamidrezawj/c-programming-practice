# Dynamic Memory Matrices in C

This folder contains exercises about working with dynamic matrices using `int **` in C.

The main topics covered:

- Dynamic memory allocation
- `malloc` and `calloc`
- Creating 2D matrices with `int **`
- Proper memory deallocation with `free`
- Matrix traversal
- Matrix searching algorithms


---

# 1. Matrix Create, Free, Print

File:

`matrix_create_free_print.c`

## Description

Creates a dynamic matrix using `int **`.

Each row is allocated separately with `calloc`.

This exercise demonstrates:

- Allocating memory for rows
- Allocating memory for columns
- Initializing matrix values
- Printing matrix contents
- Releasing allocated memory


Matrix structure:

```text
int **matrix


matrix
 |
 +---- row 0 -> [ ][ ][ ]
 |
 +---- row 1 -> [ ][ ][ ]
 |
 +---- row 2 -> [ ][ ][ ]
```


---

# 2. Local Maximum in Matrix

File:

`matrix_local_max.c`

## Description

Finds all cells that are local maximums.

A cell is considered a local maximum if no neighbor inside
a given radius `k` has a greater value.


Example:

```text
1 2 3
4 9 5
6 7 8
```

For `k = 1`:

```
9
```

is a local maximum because none of its neighbors are greater.


Concepts learned:

- Checking matrix neighbors
- Boundary handling
- Nested loops
- Searching around a cell


---

# 3. Valid Rectangles in Matrix

File:

`matrix_valid_rectangles.c`

## Description

Finds all rectangles where the four corner values are equal.


A rectangle is defined by four points:

```text
(r1,c1) -------- (r1,c2)


(r2,c1) -------- (r2,c2)
```


A rectangle is valid when:

```text
m[r1][c1] ==
m[r1][c2] ==
m[r2][c1] ==
m[r2][c2]
```


Example:

```text
1 2 1
3 4 5
1 6 1
```

The rectangle below is valid:

```text
1       1


1       1
```


Concepts learned:

- Searching combinations
- Matrix indexing
- Comparing multiple positions
- Problem solving with matrices


---

# Learning Progress

The exercises are ordered from basic to advanced:

1. Dynamic memory management
2. Matrix traversal and neighborhood search
3. Searching patterns inside matrices


---

# Compile Example

Compile any file using:

```bash
gcc filename.c -o program
```

Run:

```bash
./program
```


---

## Summary

These exercises build a foundation for working with dynamic data structures
and algorithmic problems in C.
