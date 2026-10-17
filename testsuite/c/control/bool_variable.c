/* Storing a comparison in a _Bool and doing arithmetic with it. */
#include "test.h"

NOINLINE int f(int x) { _Bool b = x > 3; return b + b + b; }
int test_true(void) { return f(10); }
int test_false(void) { return f(1); }

// RUN: test_true = 3
// RUN: test_false = 0
