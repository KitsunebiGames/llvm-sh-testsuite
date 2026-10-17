/* Adding a comparison result. */
#include "test.h"

NOINLINE int f(int a, int b) { int c = 10; c += a > b; c += a == b; return c; }
int test_gt(void) { return f(5, 3); }
int test_eq(void) { return f(3, 3); }

// RUN: test_gt = 11
// RUN: test_eq = 11
