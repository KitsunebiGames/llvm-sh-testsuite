/* Int multiply by 65537 (0x10001). */
#include "test.h"

NOINLINE int f(int a) { return a * 65537; }

int test_pos(void) { return f(1234); }
int test_neg(void) { return f(-77); }
int test_zero(void) { return f(0); }

// RUN: test_pos = 80872658
// RUN: test_neg = -5046349
// RUN: test_zero = 0
