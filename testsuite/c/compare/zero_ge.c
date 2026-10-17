/* Greater-or-equal comparison of an int against zero. */
#include "test.h"

NOINLINE int f(int a) { return a >= 0; }

int test_neg(void) { return f(-5); }
int test_zero(void) { return f(0); }
int test_pos(void) { return f(5); }

// RUN: test_neg = 0
// RUN: test_zero = 1
// RUN: test_pos = 1
