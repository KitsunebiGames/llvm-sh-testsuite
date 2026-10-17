/* An if / else-if / else chain. */
#include "test.h"

NOINLINE int f(int x) {
    if (x < 0) return -1;
    else if (x == 0) return 0;
    else if (x < 10) return 1;
    else return 2;
}
int test_neg(void) { return f(-5); }
int test_zero(void) { return f(0); }
int test_small(void) { return f(5); }
int test_big(void) { return f(50); }

// RUN: test_neg = -1
// RUN: test_zero = 0
// RUN: test_small = 1
// RUN: test_big = 2
