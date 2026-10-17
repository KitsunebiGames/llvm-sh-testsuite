/* Subtraction of two unsigned int arguments, result truncated to unsigned int. */
#include "test.h"

NOINLINE unsigned f(unsigned a, unsigned b) { return a - b; }

int test_sub_0(void) { return f(7u, 3u); }
int test_sub_1(void) { return f(3u, 7u); }
int test_sub_2(void) { return f(0xFFFFFFF0u, 0x20u); }

// RUN: test_sub_0 = 4
// RUN: test_sub_1 = -4
// RUN: test_sub_2 = -48
