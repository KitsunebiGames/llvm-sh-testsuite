/* Signed division by a power of two (rounding toward zero). */
#include "test.h"

NOINLINE int f(int x) { return x / 8; }
int test_pos(void) { return f(1001); }
int test_neg(void) { return f(-1001); }

// RUN: test_pos = 125
// RUN: test_neg = -125
