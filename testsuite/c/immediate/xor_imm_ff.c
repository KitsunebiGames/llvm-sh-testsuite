/* Int XOR with 0xff. */
#include "test.h"

NOINLINE int f(int a) { return a ^ 0xff; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 1069
// RUN: test_neg = -180
// RUN: test_zero = 255
