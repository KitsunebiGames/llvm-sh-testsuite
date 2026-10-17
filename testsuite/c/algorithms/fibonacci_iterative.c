/* Iterative Fibonacci. */
#include "test.h"

NOINLINE int fib(int n) { int a = 0, b = 1; while (n-- > 0) { int t = a + b; a = b; b = t; } return a; }
int test_20(void) { return fib(20); }

// RUN: test_20 = 6765
