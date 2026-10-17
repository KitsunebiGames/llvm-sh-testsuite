/* Bitwise AND of two signed char arguments, result truncated to signed char. */
#include "test.h"

NOINLINE signed char f(signed char a, signed char b) { return a & b; }

int test_and_0(void) { return f(7, 3); }
int test_and_1(void) { return f(100, 60); }
int test_and_2(void) { return f(-100, -60); }
int test_and_3(void) { return f(-7, 3); }

// RUN: test_and_0 = 3
// RUN: test_and_1 = 36
// RUN: test_and_2 = -124
// RUN: test_and_3 = 1
