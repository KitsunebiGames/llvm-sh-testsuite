/* Bitwise OR of two unsigned char arguments, result truncated to unsigned char. */
#include "test.h"

NOINLINE unsigned char f(unsigned char a, unsigned char b) { return a | b; }

int test_or_0(void) { return f(7, 3); }
int test_or_1(void) { return f(200, 100); }
int test_or_2(void) { return f(3, 7); }

// RUN: test_or_0 = 7
// RUN: test_or_1 = 236
// RUN: test_or_2 = 7
