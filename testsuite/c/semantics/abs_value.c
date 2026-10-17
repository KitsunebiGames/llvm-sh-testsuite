/* Absolute value with the conditional operator. */
#include "test.h"

NOINLINE int iabs(int x) { return x < 0 ? -x : x; }
int test_neg(void) { return iabs(-42); }
int test_pos(void) { return iabs(17); }

// RUN: test_neg = 42
// RUN: test_pos = 17
