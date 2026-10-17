/* A switch with case values needing 32-bit constants. */
#include "test.h"

NOINLINE int f(int x) { switch (x) { case 0x10000: return 1; case 0x7fffffff: return 2; case -2147483647 - 1: return 3; default: return 0; } }
int test_a(void) { return f(0x10000); }
int test_b(void) { return f(0x7fffffff); }
int test_c(void) { return f(-2147483647 - 1); }
int test_d(void) { return f(5); }

// RUN: test_a = 1
// RUN: test_b = 2
// RUN: test_c = 3
// RUN: test_d = 0
