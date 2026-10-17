/* Equality comparison of two int values, as a 0/1 result. */
#include "test.h"

NOINLINE int f(int a, int b) { return a == b; }

int test_lo_hi(void) { return f(-2000000000, 2000000000); }
int test_hi_lo(void) { return f(2000000000, -2000000000); }
int test_equal(void) { return f(2000000000, 2000000000); }

// RUN: test_lo_hi = 0
// RUN: test_hi_lo = 0
// RUN: test_equal = 1
