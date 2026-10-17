/* Truncating int to short. */
#include "test.h"

NOINLINE short f(int x) { return (short)x; }

int test_0(void) { return (int)f(40000); }
int test_1(void) { return (int)f(-40000); }
int test_2(void) { return (int)f(1234); }

// RUN: test_0 = -25536
// RUN: test_1 = 25536
// RUN: test_2 = 1234
