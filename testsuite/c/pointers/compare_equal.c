/* Comparing two pointers for equality. */
#include "test.h"

int x, y;
NOINLINE int f(int *a, int *b) { return a == b; }
int test_same(void) { return f(&x, &x); }
int test_diff(void) { return f(&x, &y); }

// RUN: test_same = 1
// RUN: test_diff = 0
