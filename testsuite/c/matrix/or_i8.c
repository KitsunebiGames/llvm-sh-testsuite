/* Bitwise OR of two signed char arguments, result truncated to signed char. */
#include "test.h"

NOINLINE signed char f(signed char a, signed char b) { return a | b; }

int test_or_0(void) { return f(7, 3); }
int test_or_1(void) { return f(100, 60); }
int test_or_2(void) { return f(-100, -60); }
int test_or_3(void) { return f(-7, 3); }

// RUN: test_or_0 = 7
// RUN: test_or_1 = 124
// RUN: test_or_2 = -36
// RUN: test_or_3 = -5
