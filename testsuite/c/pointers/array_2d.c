/* Indexing a two-dimensional array. */
#include "test.h"

int grid[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
NOINLINE int f(int r, int c) { return grid[r][c]; }
int test_1_2(void) { return f(1, 2); }
int test_2_3(void) { return f(2, 3); }

// RUN: test_1_2 = 7
// RUN: test_2_3 = 12
