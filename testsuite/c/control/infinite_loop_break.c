/* For(;;) with a break. */
#include "test.h"

NOINLINE int f(int n) { int i = 0; for (;;) { if (i == n) break; i++; } return i; }
int test_9(void) { return f(9); }

// RUN: test_9 = 9
