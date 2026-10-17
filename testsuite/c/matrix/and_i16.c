/* Bitwise AND of two short arguments, result truncated to short. */
#include "test.h"

NOINLINE short f(short a, short b) { return a & b; }

int test_and_0(void) { return f(700, 300); }
int test_and_1(void) { return f(30000, 10000); }
int test_and_2(void) { return f(-30000, -10000); }
int test_and_3(void) { return f(-7, 3); }

// RUN: test_and_0 = 44
// RUN: test_and_1 = 9488
// RUN: test_and_2 = -30512
// RUN: test_and_3 = 1
