/* Signed (arithmetic) right shift by the constant 4. */
#include "test.h"

NOINLINE int f(int a) { return a >> 4; }

int test_a(void) { return f(-2147483647 - 1); }
int test_b(void) { return f(0x12345678); }
int test_c(void) { return f(-1); }

// RUN: test_a = -134217728
// RUN: test_b = 19088743
// RUN: test_c = -1
