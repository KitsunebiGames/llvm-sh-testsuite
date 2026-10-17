/* Left shift of a int by a variable count. */
#include "test.h"

NOINLINE int f(int a, int n) { return a << n; }

int test_shl_0(void) { return f(1, 30); }
int test_shl_1(void) { return f(5, 3); }
int test_shl_2(void) { return f(0x1234, 8); }

// RUN: test_shl_0 = 1073741824
// RUN: test_shl_1 = 40
// RUN: test_shl_2 = 1192960
