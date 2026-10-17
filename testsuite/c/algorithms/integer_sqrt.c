/* Integer square root by searching. */
#include "test.h"

NOINLINE int isqrt(int n) { int r = 0; while ((r + 1) * (r + 1) <= n) r++; return r; }
int test_1000(void) { return isqrt(1000); }
int test_144(void) { return isqrt(144); }

// RUN: test_1000 = 31
// RUN: test_144 = 12
