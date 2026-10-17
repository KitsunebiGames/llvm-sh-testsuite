/* Add two register arguments. */
#include "test.h"

NOINLINE int add(int a, int b) { return a + b; }

int test_add(void)     { return add(2, 3); }
int test_add_neg(void) { return add(-10, 4); }

// RUN: test_add = 5
// RUN: test_add_neg = -6
