/* Bitwise XOR of two int arguments, result truncated to int. */
#include "test.h"

NOINLINE int f(int a, int b) { return a ^ b; }

int test_xor_0(void) { return f(70000, 30000); }
int test_xor_1(void) { return f(-7, 3); }
int test_xor_2(void) { return f(123456, -654321); }

// RUN: test_xor_0 = 91200
// RUN: test_xor_1 = -6
// RUN: test_xor_2 = -530865
