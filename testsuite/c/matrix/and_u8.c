/* Bitwise AND of two unsigned char arguments, result truncated to unsigned char. */
#include "test.h"

NOINLINE unsigned char f(unsigned char a, unsigned char b) { return a & b; }

int test_and_0(void) { return f(7, 3); }
int test_and_1(void) { return f(200, 100); }
int test_and_2(void) { return f(3, 7); }

// RUN: test_and_0 = 3
// RUN: test_and_1 = 64
// RUN: test_and_2 = 3
