/* Left shift of a signed char by a variable count. */
#include "test.h"

NOINLINE signed char f(signed char a, int n) { return a << n; }

int test_shl_0(void) { return f(1, 6); }
int test_shl_1(void) { return f(3, 2); }
int test_shl_2(void) { return f(1, 7); }

// RUN: test_shl_0 = 64
// RUN: test_shl_1 = 12
// RUN: test_shl_2 = -128
