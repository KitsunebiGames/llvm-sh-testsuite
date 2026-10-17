/* Subtraction of two unsigned char arguments, result truncated to unsigned char. */
#include "test.h"

NOINLINE unsigned char f(unsigned char a, unsigned char b) { return a - b; }

int test_sub_0(void) { return f(7, 3); }
int test_sub_1(void) { return f(200, 100); }
int test_sub_2(void) { return f(3, 7); }

// RUN: test_sub_0 = 4
// RUN: test_sub_1 = 100
// RUN: test_sub_2 = 252
