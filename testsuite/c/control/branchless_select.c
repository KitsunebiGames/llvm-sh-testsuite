/* A comparison result used arithmetically. */
#include "test.h"

NOINLINE int f(int a, int b, int x) { return (a < b) * x + (a >= b) * -x; }
int test_lt(void) { return f(1, 2, 7); }
int test_ge(void) { return f(2, 1, 7); }

// RUN: test_lt = 7
// RUN: test_ge = -7
