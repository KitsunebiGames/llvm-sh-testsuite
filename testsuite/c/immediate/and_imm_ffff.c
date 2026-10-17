/* Int AND with 0xffff (zero-extend word pattern). */
#include "test.h"

NOINLINE int f(int a) { return a & 0xffff; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 1234
// RUN: test_neg = 65459
// RUN: test_zero = 0
