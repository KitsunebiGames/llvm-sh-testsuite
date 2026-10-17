/* Addition of two unsigned char arguments, result truncated to unsigned char. */
#include "test.h"

NOINLINE unsigned char f(unsigned char a, unsigned char b) { return a + b; }

int test_add_0(void) { return f(7, 3); }
int test_add_1(void) { return f(200, 100); }
int test_add_2(void) { return f(3, 7); }

// RUN: test_add_0 = 10
// RUN: test_add_1 = 44
// RUN: test_add_2 = 10
