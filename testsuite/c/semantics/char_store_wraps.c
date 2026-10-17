/* Storing an out-of-range value into a signed char. */
#include "test.h"

NOINLINE int f(int x) { signed char c = (signed char)x; c += 1; return c; }
int test_call(void) { return f(127); }

// RUN: test_call = -128
