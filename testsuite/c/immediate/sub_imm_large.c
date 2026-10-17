/* Int subtracting a large constant. */
#include "test.h"

NOINLINE int f(int a) { return a - 200000; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = -198766
// RUN: test_neg = -200077
// RUN: test_zero = -200000
