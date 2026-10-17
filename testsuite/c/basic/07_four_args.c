/* Four register arguments (r4-r7), the documented maximum. */
#include "test.h"

NOINLINE int sum4(int a, int b, int c, int d) { return a + b + c + d; }

int test_sum4(void)       { return sum4(1, 2, 3, 4); }
int test_sum4_mixed(void) { return sum4(100, -1, 20, -3); }

// RUN: test_sum4 = 10
// RUN: test_sum4_mixed = 116
