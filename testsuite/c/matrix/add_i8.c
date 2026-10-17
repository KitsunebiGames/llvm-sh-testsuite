/* Addition of two signed char arguments, result truncated to signed char. */
#include "test.h"

NOINLINE signed char f(signed char a, signed char b) { return a + b; }

int test_add_0(void) { return f(7, 3); }
int test_add_1(void) { return f(100, 60); }
int test_add_2(void) { return f(-100, -60); }
int test_add_3(void) { return f(-7, 3); }

// RUN: test_add_0 = 10
// RUN: test_add_1 = -96
// RUN: test_add_2 = 96
// RUN: test_add_3 = -4
