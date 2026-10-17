/* Addition of two unsigned int arguments, result truncated to unsigned int. */
#include "test.h"

NOINLINE unsigned f(unsigned a, unsigned b) { return a + b; }

int test_add_0(void) { return f(7u, 3u); }
int test_add_1(void) { return f(3u, 7u); }
int test_add_2(void) { return f(0xFFFFFFF0u, 0x20u); }

// RUN: test_add_0 = 10
// RUN: test_add_1 = 10
// RUN: test_add_2 = 16
