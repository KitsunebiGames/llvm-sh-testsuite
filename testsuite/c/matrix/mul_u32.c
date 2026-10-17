/* Multiplication of two unsigned int arguments, result truncated to unsigned int. */
#include "test.h"

NOINLINE unsigned f(unsigned a, unsigned b) { return a * b; }

int test_mul_0(void) { return f(7u, 3u); }
int test_mul_1(void) { return f(3u, 7u); }
int test_mul_2(void) { return f(0xFFFFFFF0u, 0x20u); }

// RUN: test_mul_0 = 21
// RUN: test_mul_1 = 21
// RUN: test_mul_2 = -512
