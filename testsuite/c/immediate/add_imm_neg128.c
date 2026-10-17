/* Int adding -128 (smallest 8-bit signed immediate). */
#include "test.h"

NOINLINE int f(int a) { return a - 128; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 1106
// RUN: test_neg = -205
// RUN: test_zero = -128
