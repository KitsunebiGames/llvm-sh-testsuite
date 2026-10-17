/* Subtraction of two unsigned short arguments, result truncated to unsigned short. */
#include "test.h"

NOINLINE unsigned short f(unsigned short a, unsigned short b) { return a - b; }

int test_sub_0(void) { return f(700, 300); }
int test_sub_1(void) { return f(60000, 10000); }
int test_sub_2(void) { return f(3, 7); }

// RUN: test_sub_0 = 400
// RUN: test_sub_1 = 50000
// RUN: test_sub_2 = 65532
