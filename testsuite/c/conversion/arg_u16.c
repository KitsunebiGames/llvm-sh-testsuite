/* Passing a unsigned short argument that the callee widens to int. */
#include "test.h"

NOINLINE int f(unsigned short c) { return c + 1000; }

int test_0(void) { int v = 65000; return f((unsigned short)v); }
int test_1(void) { int v = 3; return f((unsigned short)v); }

// RUN: test_0 = 66000
// RUN: test_1 = 1003
