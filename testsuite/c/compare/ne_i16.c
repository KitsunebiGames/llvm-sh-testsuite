/* Inequality comparison of two short values, as a 0/1 result. */
#include "test.h"

NOINLINE int f(short a, short b) { return a != b; }

int test_lo_hi(void) { return f(-30000, 20000); }
int test_hi_lo(void) { return f(20000, -30000); }
int test_equal(void) { return f(20000, 20000); }

// RUN: test_lo_hi = 1
// RUN: test_hi_lo = 1
// RUN: test_equal = 0
