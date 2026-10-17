/* A global pointer initialised with an address plus an offset. */
#include "test.h"

int arr[5] = { 1, 2, 3, 4, 5 };
int *third = &arr[2];
NOINLINE int f(void) { return third[0] * 10 + third[1]; }
int test_call(void) { return f(); }

// RUN: test_call = 34
