/* Argument order for three arguments. */
#include "test.h"

NOINLINE int f(int a, int b, int c) { return a * 100 + b * 10 + c; }
int test_call(void) { return f(1, 2, 3); }

// RUN: test_call = 123
