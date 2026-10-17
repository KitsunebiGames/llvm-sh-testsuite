/* Bitwise OR of two short arguments, result truncated to short. */
#include "test.h"

NOINLINE short f(short a, short b) { return a | b; }

int test_or_0(void) { return f(700, 300); }
int test_or_1(void) { return f(30000, 10000); }
int test_or_2(void) { return f(-30000, -10000); }
int test_or_3(void) { return f(-7, 3); }

// RUN: test_or_0 = 956
// RUN: test_or_1 = 30512
// RUN: test_or_2 = -9488
// RUN: test_or_3 = -5
