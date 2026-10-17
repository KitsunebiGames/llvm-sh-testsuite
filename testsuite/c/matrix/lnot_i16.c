/* Logical NOT of a short argument. */
#include "test.h"

NOINLINE int f(short a) { return !a; }

int test_lnot_0(void) { return f(0); }
int test_lnot_1(void) { return f(-32768); }

// RUN: test_lnot_0 = 1
// RUN: test_lnot_1 = 0
