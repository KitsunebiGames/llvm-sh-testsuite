/* A counting-up for loop. */
#include "test.h"

NOINLINE int f(int n) { int c = 0; for (int i = 0; i < n; i++) c += 2; return c; }
int test_7(void) { return f(7); }

// RUN: test_7 = 14
