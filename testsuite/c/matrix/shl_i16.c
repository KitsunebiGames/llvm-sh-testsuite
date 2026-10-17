/* Left shift of a short by a variable count. */
#include "test.h"

NOINLINE short f(short a, int n) { return a << n; }

int test_shl_0(void) { return f(1, 14); }
int test_shl_1(void) { return f(3, 4); }
int test_shl_2(void) { return f(1, 15); }

// RUN: test_shl_0 = 16384
// RUN: test_shl_1 = 48
// RUN: test_shl_2 = -32768
