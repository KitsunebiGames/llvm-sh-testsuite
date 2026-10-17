/* The ^= compound assignment. */
#include "test.h"

NOINLINE int f(int a, int b) { int x = a; x ^= b; return x; }
int test_call(void) { return f(1000, 3); }

// RUN: test_call = 1003
