/* A while (--n) countdown loop. */
#include "test.h"

NOINLINE int f(int n) { int c = 0; while (--n) c += 3; return c; }
int test_5(void) { return f(5); }
int test_1(void) { return f(1); }

// RUN: test_5 = 12
// RUN: test_1 = 0
