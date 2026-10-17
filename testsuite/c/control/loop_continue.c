/* Continue skipping the rest of a loop body. */
#include "test.h"

NOINLINE int f(int n) { int s = 0; for (int i = 0; i < n; i++) { if ((i & 1) == 0) continue; s += i; } return s; }
int test_10(void) { return f(10); }

// RUN: test_10 = 25
