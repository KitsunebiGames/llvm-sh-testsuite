/* Left shift of a unsigned char by a variable count. */
#include "test.h"

NOINLINE unsigned char f(unsigned char a, int n) { return a << n; }

int test_shl_0(void) { return f(1, 7); }
int test_shl_1(void) { return f(255, 1); }

// RUN: test_shl_0 = 128
// RUN: test_shl_1 = 254
