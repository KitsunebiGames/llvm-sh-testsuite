/* Logical NOT of a int argument. */
#include "test.h"

NOINLINE int f(int a) { return !a; }

int test_lnot_0(void) { return f(0); }
int test_lnot_1(void) { return f(-2147483647); }

// RUN: test_lnot_0 = 1
// RUN: test_lnot_1 = 0
