/* A function ignoring some of its parameters. */
#include "test.h"

NOINLINE int f(int a, int b, int c, int d) { (void)a; (void)c; return b - d; }
int test_call(void) { return f(100, 50, 200, 8); }

// RUN: test_call = 42
