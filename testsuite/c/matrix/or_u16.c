/* Bitwise OR of two unsigned short arguments, result truncated to unsigned short. */
#include "test.h"

NOINLINE unsigned short f(unsigned short a, unsigned short b) { return a | b; }

int test_or_0(void) { return f(700, 300); }
int test_or_1(void) { return f(60000, 10000); }
int test_or_2(void) { return f(3, 7); }

// RUN: test_or_0 = 956
// RUN: test_or_1 = 61296
// RUN: test_or_2 = 7
