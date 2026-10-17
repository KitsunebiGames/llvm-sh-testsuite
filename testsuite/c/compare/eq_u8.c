/* Equality comparison of two unsigned char values, as a 0/1 result. */
#include "test.h"

NOINLINE int f(unsigned char a, unsigned char b) { return a == b; }

int test_lo_hi(void) { return f(50, 200); }
int test_hi_lo(void) { return f(200, 50); }
int test_equal(void) { return f(200, 200); }

// RUN: test_lo_hi = 0
// RUN: test_hi_lo = 0
// RUN: test_equal = 1
