/* Writing and reading the same union member. */
#include "test.h"

union u { int i; short s; char c; };
NOINLINE int f(int v) { union u x; x.i = v; return x.i; }
int test_call(void) { return f(123456); }

// RUN: test_call = 123456
