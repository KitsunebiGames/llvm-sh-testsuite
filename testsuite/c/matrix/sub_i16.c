/* Subtraction of two short arguments, result truncated to short. */
#include "test.h"

NOINLINE short f(short a, short b) { return a - b; }

int test_sub_0(void) { return f(700, 300); }
int test_sub_1(void) { return f(30000, 10000); }
int test_sub_2(void) { return f(-30000, -10000); }
int test_sub_3(void) { return f(-7, 3); }

// RUN: test_sub_0 = 400
// RUN: test_sub_1 = 20000
// RUN: test_sub_2 = -20000
// RUN: test_sub_3 = -10
