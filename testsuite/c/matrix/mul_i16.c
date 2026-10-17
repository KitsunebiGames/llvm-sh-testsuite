/* Multiplication of two short arguments, result truncated to short. */
#include "test.h"

NOINLINE short f(short a, short b) { return a * b; }

int test_mul_0(void) { return f(700, 300); }
int test_mul_1(void) { return f(30000, 10000); }
int test_mul_2(void) { return f(-30000, -10000); }
int test_mul_3(void) { return f(-7, 3); }

// RUN: test_mul_0 = 13392
// RUN: test_mul_1 = -23808
// RUN: test_mul_2 = -23808
// RUN: test_mul_3 = -21
