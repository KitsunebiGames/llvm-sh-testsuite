/* Bitwise OR of two int arguments, result truncated to int. */
#include "test.h"

NOINLINE int f(int a, int b) { return a | b; }

int test_or_0(void) { return f(70000, 30000); }
int test_or_1(void) { return f(-7, 3); }
int test_or_2(void) { return f(123456, -654321); }

// RUN: test_or_0 = 95600
// RUN: test_or_1 = -5
// RUN: test_or_2 = -530865
