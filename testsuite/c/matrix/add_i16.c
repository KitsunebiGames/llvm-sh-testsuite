/* Addition of two short arguments, result truncated to short. */
#include "test.h"

NOINLINE short f(short a, short b) { return a + b; }

int test_add_0(void) { return f(700, 300); }
int test_add_1(void) { return f(30000, 10000); }
int test_add_2(void) { return f(-30000, -10000); }
int test_add_3(void) { return f(-7, 3); }

// RUN: test_add_0 = 1000
// RUN: test_add_1 = -25536
// RUN: test_add_2 = 25536
// RUN: test_add_3 = -4
