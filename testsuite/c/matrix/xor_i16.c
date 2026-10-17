/* Bitwise XOR of two short arguments, result truncated to short. */
#include "test.h"

NOINLINE short f(short a, short b) { return a ^ b; }

int test_xor_0(void) { return f(700, 300); }
int test_xor_1(void) { return f(30000, 10000); }
int test_xor_2(void) { return f(-30000, -10000); }
int test_xor_3(void) { return f(-7, 3); }

// RUN: test_xor_0 = 912
// RUN: test_xor_1 = 21024
// RUN: test_xor_2 = 21024
// RUN: test_xor_3 = -6
