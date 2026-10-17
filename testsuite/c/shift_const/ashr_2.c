/* Signed (arithmetic) right shift by the constant 2. */
#include "test.h"

NOINLINE int f(int a) { return a >> 2; }

int test_a(void) { return f(-2147483647 - 1); }
int test_b(void) { return f(0x12345678); }
int test_c(void) { return f(-1); }

// RUN: test_a = -536870912
// RUN: test_b = 76354974
// RUN: test_c = -1
