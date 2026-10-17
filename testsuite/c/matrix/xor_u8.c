/* Bitwise XOR of two unsigned char arguments, result truncated to unsigned char. */
#include "test.h"

NOINLINE unsigned char f(unsigned char a, unsigned char b) { return a ^ b; }

int test_xor_0(void) { return f(7, 3); }
int test_xor_1(void) { return f(200, 100); }
int test_xor_2(void) { return f(3, 7); }

// RUN: test_xor_0 = 4
// RUN: test_xor_1 = 172
// RUN: test_xor_2 = 4
