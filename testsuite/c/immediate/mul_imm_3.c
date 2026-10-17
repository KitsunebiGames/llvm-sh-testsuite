/* Int multiply by 3. */
#include "test.h"

NOINLINE int f(int a) { return a * 3; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 3702
// RUN: test_neg = -231
// RUN: test_zero = 0
