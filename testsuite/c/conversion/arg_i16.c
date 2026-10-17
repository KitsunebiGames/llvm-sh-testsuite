/* Passing a short argument that the callee widens to int. */
#include "test.h"

NOINLINE int f(short c) { return c + 1000; }

int test_0(void) { int v = -3; return f((short)v); }
int test_1(void) { int v = 30000; return f((short)v); }

// RUN: test_0 = 997
// RUN: test_1 = 31000
