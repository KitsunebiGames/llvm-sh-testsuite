/* A chain of functions each calling the next. */
#include "test.h"

NOINLINE int c3(int x) { return x + 3; }
NOINLINE int c2(int x) { return c3(x) * 2; }
NOINLINE int c1(int x) { return c2(x) - 1; }
int test_call(void) { return c1(5); }

// RUN: test_call = 15
