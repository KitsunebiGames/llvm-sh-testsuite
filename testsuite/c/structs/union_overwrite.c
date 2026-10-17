/* A later union member write replacing an earlier one. */
#include "test.h"

union u { int i; unsigned u; };
NOINLINE int f(void) { union u x; x.i = -1; x.u = 5u; return x.i; }
int test_call(void) { return f(); }

// RUN: test_call = 5
