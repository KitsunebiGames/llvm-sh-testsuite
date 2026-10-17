/* A switch whose cases are negative. */
#include "test.h"

NOINLINE int f(int x) { switch (x) { case -3: return 3; case -2: return 2; case -1: return 1; default: return 0; } }
int test_m3(void) { return f(-3); }
int test_m1(void) { return f(-1); }
int test_0(void) { return f(0); }

// RUN: test_m3 = 3
// RUN: test_m1 = 1
// RUN: test_0 = 0
