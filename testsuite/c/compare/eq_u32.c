/* Equality comparison of two unsigned int values, as a 0/1 result. */
#include "test.h"

NOINLINE int f(unsigned a, unsigned b) { return a == b; }

int test_lo_hi(void) { return f(1u, 0xF0000000u); }
int test_hi_lo(void) { return f(0xF0000000u, 1u); }
int test_equal(void) { return f(0xF0000000u, 0xF0000000u); }

// RUN: test_lo_hi = 0
// RUN: test_hi_lo = 0
// RUN: test_equal = 1
