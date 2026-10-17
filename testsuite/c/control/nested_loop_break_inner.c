/* Break leaving only the inner of two loops. */
#include "test.h"

NOINLINE int f(int n) { int c = 0; for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) { if (j > i) break; c++; } return c; }
int test_5(void) { return f(5); }

// RUN: test_5 = 15
