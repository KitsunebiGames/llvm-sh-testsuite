/* Indexing a pointer with a negative index. */
#include "test.h"

int arr[5] = { 10, 20, 30, 40, 50 };
NOINLINE int f(int *p) { return p[-2]; }
int test_call(void) { return f(&arr[4]); }

// RUN: test_call = 30
