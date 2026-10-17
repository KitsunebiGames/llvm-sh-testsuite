/* Comparing two pointers with <. */
#include "test.h"

int arr[4];
NOINLINE int f(int *a, int *b) { return a < b; }
int test_lt(void) { return f(&arr[0], &arr[3]); }
int test_gt(void) { return f(&arr[3], &arr[0]); }

// RUN: test_lt = 1
// RUN: test_gt = 0
