/* An if statement without an else. */
#include "test.h"

NOINLINE int f(int x) { int r = 1; if (x) r = 2; return r; }
int test_true(void) { return f(5); }
int test_false(void) { return f(0); }

// RUN: test_true = 2
// RUN: test_false = 1
