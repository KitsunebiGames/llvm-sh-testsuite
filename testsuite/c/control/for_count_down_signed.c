/* A signed for loop counting down to zero. */
#include "test.h"

NOINLINE int f(int n) { int s = 0; for (int i = n; i >= 0; i--) s += i; return s; }
int test_5(void) { return f(5); }
int test_neg(void) { return f(-1); }

// RUN: test_5 = 15
// RUN: test_neg = 0
