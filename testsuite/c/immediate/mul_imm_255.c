/* Int multiply by 255. */
#include "test.h"

NOINLINE int f(int a) { return a * 255; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 314670
// RUN: test_neg = -19635
// RUN: test_zero = 0
