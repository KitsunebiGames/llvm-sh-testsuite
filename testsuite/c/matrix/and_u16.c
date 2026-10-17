/* Bitwise AND of two unsigned short arguments, result truncated to unsigned short. */
#include "test.h"

NOINLINE unsigned short f(unsigned short a, unsigned short b) { return a & b; }

int test_and_0(void) { return f(700, 300); }
int test_and_1(void) { return f(60000, 10000); }
int test_and_2(void) { return f(3, 7); }

// RUN: test_and_0 = 44
// RUN: test_and_1 = 8704
// RUN: test_and_2 = 3
