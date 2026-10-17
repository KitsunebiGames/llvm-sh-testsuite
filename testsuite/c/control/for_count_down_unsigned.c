/* An unsigned loop counting down with i-- > 0. */
#include "test.h"

NOINLINE int f(unsigned n) { int s = 0; for (unsigned i = n; i-- > 0;) s += (int)i; return s; }
int test_5(void) { return f(5u); }
int test_0(void) { return f(0u); }

// RUN: test_5 = 10
// RUN: test_0 = 0
