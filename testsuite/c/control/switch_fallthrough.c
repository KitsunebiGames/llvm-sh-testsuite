/* Switch cases falling through to the next case. */
#include "test.h"

NOINLINE int f(int x) { int r = 0; switch (x) { case 0: r += 1; case 1: r += 10; case 2: r += 100; break; case 3: r = 5; } return r; }
int test_0(void) { return f(0); }
int test_1(void) { return f(1); }
int test_2(void) { return f(2); }
int test_3(void) { return f(3); }

// RUN: test_0 = 111
// RUN: test_1 = 110
// RUN: test_2 = 100
// RUN: test_3 = 5
