/* Swapping two ints through pointers. */
#include "test.h"

NOINLINE void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }
int test_call(void) { int x = 3, y = 8; swap(&x, &y); return x * 10 + y; }

// RUN: test_call = 83
