/* Addition of two unsigned short arguments, result truncated to unsigned short. */
#include "test.h"

NOINLINE unsigned short f(unsigned short a, unsigned short b) { return a + b; }

int test_add_0(void) { return f(700, 300); }
int test_add_1(void) { return f(60000, 10000); }
int test_add_2(void) { return f(3, 7); }

// RUN: test_add_0 = 1000
// RUN: test_add_1 = 4464
// RUN: test_add_2 = 10
