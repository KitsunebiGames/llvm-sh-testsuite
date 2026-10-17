/* Using one call result in two places. */
#include "test.h"

NOINLINE int g(int x) { return x + 3; }
NOINLINE int f(int x) { int r = g(x); return r * r - r; }
int test_call(void) { return f(4); }

// RUN: test_call = 42
