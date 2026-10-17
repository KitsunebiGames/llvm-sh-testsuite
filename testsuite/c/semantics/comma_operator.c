/* The comma operator evaluating to its last operand. */
#include "test.h"

NOINLINE int f(int a) { int b = (a += 2, a * 3); return b + a; }
int test_call(void) { return f(4); }

// RUN: test_call = 24
