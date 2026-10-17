/* A switch with sparse case values. */
#include "test.h"

NOINLINE int f(int x) {
    switch (x) { case 1: return 1; case 100: return 2; case 1000: return 3; case -5: return 4; default: return 0; }
}
int test_1(void) { return f(1); }
int test_100(void) { return f(100); }
int test_1000(void) { return f(1000); }
int test_m5(void) { return f(-5); }
int test_none(void) { return f(50); }

// RUN: test_1 = 1
// RUN: test_100 = 2
// RUN: test_1000 = 3
// RUN: test_m5 = 4
// RUN: test_none = 0
