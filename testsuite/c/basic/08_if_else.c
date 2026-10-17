/* Conditional branch on a signed compare. */
#include "test.h"

NOINLINE int max(int a, int b) { if (a > b) return a; else return b; }

int test_max_second(void) { return max(3, 9); }
int test_max_first(void)  { return max(9, 3); }
int test_max_neg(void)    { return max(-2, -5); }
int test_max_equal(void)  { return max(4, 4); }

// RUN: test_max_second = 9
// RUN: test_max_first = 9
// RUN: test_max_neg = -2
// RUN: test_max_equal = 4
