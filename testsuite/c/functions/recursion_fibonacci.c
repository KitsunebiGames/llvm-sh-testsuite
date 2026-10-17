/* Double recursion (Fibonacci). */
#include "test.h"

NOINLINE int fib(int n) { return n < 2 ? n : fib(n - 1) + fib(n - 2); }
int test_15(void) { return fib(15); }

// RUN: test_15 = 610
