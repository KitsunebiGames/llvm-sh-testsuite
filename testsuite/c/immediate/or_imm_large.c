/* Int OR with a constant above the immediate range. */
#include "test.h"

NOINLINE int f(int a) { return a | 0x10000; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 66770
// RUN: test_neg = -77
// RUN: test_zero = 65536
