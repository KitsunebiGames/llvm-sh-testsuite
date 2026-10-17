/* A while loop accumulating a sum. */
#include "test.h"

NOINLINE int f(int n) { int s = 0, i = 1; while (i <= n) { s += i; i++; } return s; }
int test_10(void) { return f(10); }
int test_0(void) { return f(0); }

// RUN: test_10 = 55
// RUN: test_0 = 0
