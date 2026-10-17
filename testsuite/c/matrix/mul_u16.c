/* Multiplication of two unsigned short arguments, result truncated to unsigned short. */
#include "test.h"

NOINLINE unsigned short f(unsigned short a, unsigned short b) { return a * b; }

int test_mul_0(void) { return f(700, 300); }
int test_mul_1(void) { return f(60000, 10000); }
int test_mul_2(void) { return f(3, 7); }

// RUN: test_mul_0 = 13392
// RUN: test_mul_1 = 17920
// RUN: test_mul_2 = 21
