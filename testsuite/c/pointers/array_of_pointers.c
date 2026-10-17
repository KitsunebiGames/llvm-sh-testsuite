/* An array of pointers. */
#include "test.h"

int a = 1, b = 2, c = 3;
int *ptrs[3] = { &c, &a, &b };
NOINLINE int f(int i) { return *ptrs[i]; }
int test_call(void) { return f(0) * 100 + f(1) * 10 + f(2); }

// RUN: test_call = 312
