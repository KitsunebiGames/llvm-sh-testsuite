/* A sign function returning -1, 0 or 1. */
#include "test.h"

NOINLINE int sgn(int x) { return (x > 0) - (x < 0); }
int test_neg(void) { return sgn(-9); }
int test_zero(void) { return sgn(0); }
int test_pos(void) { return sgn(9); }

// RUN: test_neg = -1
// RUN: test_zero = 0
// RUN: test_pos = 1
