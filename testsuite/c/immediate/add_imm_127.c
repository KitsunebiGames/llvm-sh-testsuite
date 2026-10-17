/* Int adding 127 (largest 8-bit signed immediate). */
#include "test.h"

NOINLINE int f(int a) { return a + 127; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 1361
// RUN: test_neg = 50
// RUN: test_zero = 127
