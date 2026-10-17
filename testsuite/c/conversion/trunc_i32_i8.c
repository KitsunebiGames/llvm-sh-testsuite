/* Truncating int to signed char. */
#include "test.h"

NOINLINE signed char f(int x) { return (signed char)x; }

int test_0(void) { return (int)f(300); }
int test_1(void) { return (int)f(200); }
int test_2(void) { return (int)f(-129); }
int test_3(void) { return (int)f(77); }

// RUN: test_0 = 44
// RUN: test_1 = -56
// RUN: test_2 = 127
// RUN: test_3 = 77
