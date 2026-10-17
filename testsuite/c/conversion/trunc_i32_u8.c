/* Truncating int to unsigned char. */
#include "test.h"

NOINLINE unsigned char f(int x) { return (unsigned char)x; }

int test_0(void) { return (int)f(300); }
int test_1(void) { return (int)f(-1); }
int test_2(void) { return (int)f(77); }

// RUN: test_0 = 44
// RUN: test_1 = 255
// RUN: test_2 = 77
