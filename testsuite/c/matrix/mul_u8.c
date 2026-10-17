/* Multiplication of two unsigned char arguments, result truncated to unsigned char. */
#include "test.h"

NOINLINE unsigned char f(unsigned char a, unsigned char b) { return a * b; }

int test_mul_0(void) { return f(7, 3); }
int test_mul_1(void) { return f(200, 100); }
int test_mul_2(void) { return f(3, 7); }

// RUN: test_mul_0 = 21
// RUN: test_mul_1 = 32
// RUN: test_mul_2 = 21
