/* Post-decrement returning the old value. */
#include "test.h"

NOINLINE int f(int x) { int y = x--; return y * 100 + x; }
int test_call(void) { return f(5); }

// RUN: test_call = 504
