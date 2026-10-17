/* Int adding a constant that needs a constant-pool load. */
#include "test.h"

NOINLINE int f(int a) { return a + 100000; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 101234
// RUN: test_neg = 99923
// RUN: test_zero = 100000
