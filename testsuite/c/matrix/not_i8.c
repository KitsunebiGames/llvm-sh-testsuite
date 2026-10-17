/* Bitwise NOT of a signed char argument. */
#include "test.h"

NOINLINE signed char f(signed char a) { return ~a; }

int test_not_0(void) { return f(0); }
int test_not_1(void) { return f(5); }
int test_not_2(void) { return f(-1); }

// RUN: test_not_0 = -1
// RUN: test_not_1 = -6
// RUN: test_not_2 = 0
