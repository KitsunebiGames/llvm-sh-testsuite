/* Int AND with a large mask. */
#include "test.h"

NOINLINE int f(int a) { return a & 0x7ffffff0; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 1232
// RUN: test_neg = 2147483568
// RUN: test_zero = 0
