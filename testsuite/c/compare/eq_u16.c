/* Equality comparison of two unsigned short values, as a 0/1 result. */
#include "test.h"

NOINLINE int f(unsigned short a, unsigned short b) { return a == b; }

int test_lo_hi(void) { return f(1000, 60000); }
int test_hi_lo(void) { return f(60000, 1000); }
int test_equal(void) { return f(60000, 60000); }

// RUN: test_lo_hi = 0
// RUN: test_hi_lo = 0
// RUN: test_equal = 1
