/* Signed remainder by a power of two (sign follows the dividend). */
#include "test.h"

NOINLINE int f(int x) { return x % 16; }
int test_pos(void) { return f(1001); }
int test_neg(void) { return f(-1001); }

// RUN: test_pos = 9
// RUN: test_neg = -9
