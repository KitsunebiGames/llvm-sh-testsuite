/* Int multiply by 10. */
#include "test.h"

NOINLINE int f(int a) { return a * 10; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 12340
// RUN: test_neg = -770
// RUN: test_zero = 0
