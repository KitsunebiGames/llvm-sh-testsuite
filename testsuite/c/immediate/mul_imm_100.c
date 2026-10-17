/* Int multiply by 100. */
#include "test.h"

NOINLINE int f(int a) { return a * 100; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 123400
// RUN: test_neg = -7700
// RUN: test_zero = 0
