/* Logical NOT of a unsigned short argument. */
#include "test.h"

NOINLINE int f(unsigned short a) { return !a; }

int test_lnot_0(void) { return f(0); }
int test_lnot_1(void) { return f(65535); }

// RUN: test_lnot_0 = 1
// RUN: test_lnot_1 = 0
