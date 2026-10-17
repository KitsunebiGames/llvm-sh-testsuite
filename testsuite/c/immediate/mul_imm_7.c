/* Int multiply by 7. */
#include "test.h"

NOINLINE int f(int a) { return a * 7; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 8638
// RUN: test_neg = -539
// RUN: test_zero = 0
