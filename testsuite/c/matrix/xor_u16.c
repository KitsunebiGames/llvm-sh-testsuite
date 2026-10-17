/* Bitwise XOR of two unsigned short arguments, result truncated to unsigned short. */
#include "test.h"

NOINLINE unsigned short f(unsigned short a, unsigned short b) { return a ^ b; }

int test_xor_0(void) { return f(700, 300); }
int test_xor_1(void) { return f(60000, 10000); }
int test_xor_2(void) { return f(3, 7); }

// RUN: test_xor_0 = 912
// RUN: test_xor_1 = 52592
// RUN: test_xor_2 = 4
