/* Two nested loops. */
#include "test.h"

NOINLINE int f(int n) { int c = 0; for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) c++; return c; }
int test_6(void) { return f(6); }

// RUN: test_6 = 15
