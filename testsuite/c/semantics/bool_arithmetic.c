/* Arithmetic on _Bool values. */
#include "test.h"

NOINLINE int f(int a, int b) { _Bool x = a, y = b; return x + y + (x & y) * 10; }
int test_call(void) { return f(7, -2); }

// RUN: test_call = 12
