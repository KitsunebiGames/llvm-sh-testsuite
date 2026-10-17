/* Logical NOT of a unsigned int argument. */
#include "test.h"

NOINLINE int f(unsigned a) { return !a; }

int test_lnot_0(void) { return f(0u); }
int test_lnot_1(void) { return f(0x80000000u); }

// RUN: test_lnot_0 = 1
// RUN: test_lnot_1 = 0
