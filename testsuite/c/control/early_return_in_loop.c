/* Returning from inside a loop. */
#include "test.h"

NOINLINE int f(int n) { for (int i = 0; i < 100; i++) if (i * i >= n) return i; return -1; }
int test_50(void) { return f(50); }
int test_big(void) { return f(100000); }

// RUN: test_50 = 8
// RUN: test_big = -1
