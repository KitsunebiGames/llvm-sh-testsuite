/* Passing expression results as arguments. */
#include "test.h"

NOINLINE int g(int a, int b) { return a * b; }
NOINLINE int f(int x, int y) { return g(x + y, x - y); }
int test_call(void) { return f(7, 3); }

// RUN: test_call = 40
