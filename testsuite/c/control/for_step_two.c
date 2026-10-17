/* A for loop with a step of 2. */
#include "test.h"

NOINLINE int f(int n) { int c = 0; for (int i = 0; i < n; i += 2) c++; return c; }
int test_10(void) { return f(10); }
int test_11(void) { return f(11); }

// RUN: test_10 = 5
// RUN: test_11 = 6
