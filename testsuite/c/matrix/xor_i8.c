/* Bitwise XOR of two signed char arguments, result truncated to signed char. */
#include "test.h"

NOINLINE signed char f(signed char a, signed char b) { return a ^ b; }

int test_xor_0(void) { return f(7, 3); }
int test_xor_1(void) { return f(100, 60); }
int test_xor_2(void) { return f(-100, -60); }
int test_xor_3(void) { return f(-7, 3); }

// RUN: test_xor_0 = 4
// RUN: test_xor_1 = 88
// RUN: test_xor_2 = 88
// RUN: test_xor_3 = -6
