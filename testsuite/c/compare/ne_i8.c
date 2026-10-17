/* Inequality comparison of two signed char values, as a 0/1 result. */
#include "test.h"

NOINLINE int f(signed char a, signed char b) { return a != b; }

int test_lo_hi(void) { return f(-100, 50); }
int test_hi_lo(void) { return f(50, -100); }
int test_equal(void) { return f(50, 50); }

// RUN: test_lo_hi = 1
// RUN: test_hi_lo = 1
// RUN: test_equal = 0
