/* Int AND with 0x0f (fits and #imm). */
#include "test.h"

NOINLINE int f(int a) { return a & 0x0f; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 2
// RUN: test_neg = 3
// RUN: test_zero = 0
