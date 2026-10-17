/* Passing a unsigned char argument that the callee widens to int. */
#include "test.h"

NOINLINE int f(unsigned char c) { return c + 1000; }

int test_0(void) { int v = 250; return f((unsigned char)v); }
int test_1(void) { int v = 3; return f((unsigned char)v); }

// RUN: test_0 = 1250
// RUN: test_1 = 1003
