/* Multiply (mul.l / dmul.s + sts macl). */
#include "test.h"

NOINLINE int mul(int a, int b) { return a * b; }

int test_mul(void)     { return mul(6, 7); }
int test_mul_neg(void) { return mul(-3, 7); }

// RUN: test_mul = 42
// RUN: test_mul_neg = -21
