/* Passing a signed char argument that the callee widens to int. */
#include "test.h"

NOINLINE int f(signed char c) { return c + 1000; }

int test_0(void) { int v = -3; return f((signed char)v); }
int test_1(void) { int v = 100; return f((signed char)v); }

// RUN: test_0 = 997
// RUN: test_1 = 1100
