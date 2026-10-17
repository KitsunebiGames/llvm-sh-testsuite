/* Less-or-equal comparison of two unsigned int values controlling an if/else. */
#include "test.h"

NOINLINE int f(unsigned a, unsigned b) { if (a <= b) return 10; return 20; }

int test_lo_hi(void) { return f(1u, 0xF0000000u); }
int test_hi_lo(void) { return f(0xF0000000u, 1u); }
int test_equal(void) { return f(0xF0000000u, 0xF0000000u); }

// RUN: test_lo_hi = 10
// RUN: test_hi_lo = 20
// RUN: test_equal = 10
