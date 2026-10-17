/* Min and max of two ints. */
#include "test.h"

NOINLINE int imin(int a, int b) { return a < b ? a : b; }
NOINLINE int imax(int a, int b) { return a > b ? a : b; }
int test_call(void) { return imin(-3, 8) * 100 + imax(-3, 8); }

// RUN: test_call = -292
