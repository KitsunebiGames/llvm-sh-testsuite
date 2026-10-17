/* Calls nested inside call arguments. */
#include "test.h"

NOINLINE int inc(int x) { return x + 1; }
NOINLINE int dbl(int x) { return x * 2; }
int test_call(void) { return dbl(inc(dbl(inc(3)))); }

// RUN: test_call = 18
