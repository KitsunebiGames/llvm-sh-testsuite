/* Nested if statements. */
#include "test.h"

NOINLINE int f(int a, int b) {
    if (a > 0) { if (b > 0) return 1; else return 2; }
    else { if (b > 0) return 3; else return 4; }
}
int test_pp(void) { return f(1, 1); }
int test_pn(void) { return f(1, -1); }
int test_np(void) { return f(-1, 1); }
int test_nn(void) { return f(-1, -1); }

// RUN: test_pp = 1
// RUN: test_pn = 2
// RUN: test_np = 3
// RUN: test_nn = 4
