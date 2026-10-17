/* Left shift of a unsigned short by a variable count. */
#include "test.h"

NOINLINE unsigned short f(unsigned short a, int n) { return a << n; }

int test_shl_0(void) { return f(1, 15); }
int test_shl_1(void) { return f(0xffff, 4); }

// RUN: test_shl_0 = 32768
// RUN: test_shl_1 = 65520
