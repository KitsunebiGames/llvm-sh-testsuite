/* Multiplication of two signed char arguments, result truncated to signed char. */
#include "test.h"

NOINLINE signed char f(signed char a, signed char b) { return a * b; }

int test_mul_0(void) { return f(7, 3); }
int test_mul_1(void) { return f(100, 60); }
int test_mul_2(void) { return f(-100, -60); }
int test_mul_3(void) { return f(-7, 3); }

// RUN: test_mul_0 = 21
// RUN: test_mul_1 = 112
// RUN: test_mul_2 = 112
// RUN: test_mul_3 = -21
