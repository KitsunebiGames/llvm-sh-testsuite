/* Int XOR with a large constant. */
#include "test.h"

NOINLINE int f(int a) { return a ^ 0x12345; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 75671
// RUN: test_neg = -74506
// RUN: test_zero = 74565
