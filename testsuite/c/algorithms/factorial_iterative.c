/* Iterative factorial. */
#include "test.h"

NOINLINE int fact(int n) { int r = 1; for (int i = 2; i <= n; i++) r *= i; return r; }
int test_12(void) { return fact(12); }

// RUN: test_12 = 479001600
