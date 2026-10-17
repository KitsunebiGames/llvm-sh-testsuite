/* Subtracting from a pointer. */
#include "test.h"

int arr[5] = { 1, 2, 3, 4, 5 };
NOINLINE int f(int *end, int n) { return *(end - n); }
int test_call(void) { return f(&arr[4], 3); }

// RUN: test_call = 2
