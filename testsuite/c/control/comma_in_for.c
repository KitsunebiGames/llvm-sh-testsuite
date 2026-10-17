/* A for loop with comma-separated updates. */
#include "test.h"

NOINLINE int f(int n) { int i, j, s = 0; for (i = 0, j = n; i < j; i++, j--) s += j - i; return s; }
int test_10(void) { return f(10); }

// RUN: test_10 = 30
