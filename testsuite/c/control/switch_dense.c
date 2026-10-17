/* A switch with dense case values (jump-table candidate). */
#include "test.h"

NOINLINE int f(int x) {
    switch (x) {
    case 0: return 10; case 1: return 11; case 2: return 12; case 3: return 13;
    case 4: return 14; case 5: return 15; case 6: return 16; case 7: return 17;
    default: return -1;
    }
}
int test_0(void) { return f(0); }
int test_5(void) { return f(5); }
int test_7(void) { return f(7); }
int test_out(void) { return f(8); }
int test_neg(void) { return f(-1); }

// RUN: test_0 = 10
// RUN: test_5 = 15
// RUN: test_7 = 17
// RUN: test_out = -1
// RUN: test_neg = -1
