/* Bitwise AND of two int arguments, result truncated to int. */
#include "test.h"

NOINLINE int f(int a, int b) { return a & b; }

int test_and_0(void) { return f(70000, 30000); }
int test_and_1(void) { return f(-7, 3); }
int test_and_2(void) { return f(123456, -654321); }

// RUN: test_and_0 = 4400
// RUN: test_and_1 = 1
// RUN: test_and_2 = 0
