/* Signed division by the constant 10. */
#include "test.h"

NOINLINE int f(int x) { return x / 10; }
int test_pos(void) { return f(12345); }
int test_neg(void) { return f(-12345); }

// RUN: test_pos = 1234
// RUN: test_neg = -1234
