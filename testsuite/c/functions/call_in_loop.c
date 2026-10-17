/* Calling a function on every iteration of a loop. */
#include "test.h"

NOINLINE int sq(int x) { return x * x; }
NOINLINE int f(int n) { int s = 0; for (int i = 1; i <= n; i++) s += sq(i); return s; }
int test_5(void) { return f(5); }

// RUN: test_5 = 55
