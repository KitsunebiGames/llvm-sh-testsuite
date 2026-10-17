/* Subtraction of two signed char arguments, result truncated to signed char. */
#include "test.h"

NOINLINE signed char f(signed char a, signed char b) { return a - b; }

int test_sub_0(void) { return f(7, 3); }
int test_sub_1(void) { return f(100, 60); }
int test_sub_2(void) { return f(-100, -60); }
int test_sub_3(void) { return f(-7, 3); }

// RUN: test_sub_0 = 4
// RUN: test_sub_1 = 40
// RUN: test_sub_2 = -40
// RUN: test_sub_3 = -10
