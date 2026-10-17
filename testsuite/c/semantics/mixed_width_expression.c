/* An expression mixing char, short and int. */
#include "test.h"

NOINLINE int f(signed char c, short s, int i) { return c * s + i; }
int test_call(void) { return f(-7, 1000, 50000); }

// RUN: test_call = 43000
