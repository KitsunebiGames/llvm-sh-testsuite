/* A condition combining &&, || and !. */
#include "test.h"

NOINLINE int f(int a, int b, int c) { return (a > 0 && b > 0) || !c; }
int test_a(void) { return f(1, 1, 1); }
int test_b(void) { return f(1, -1, 1); }
int test_c(void) { return f(-1, -1, 0); }

// RUN: test_a = 1
// RUN: test_b = 0
// RUN: test_c = 1
