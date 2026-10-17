/* Argument order for two arguments. */
#include "test.h"

NOINLINE int f(int a, int b) { return a * 10 + b; }
int test_call(void) { return f(4, 2); }

// RUN: test_call = 42
