/* Char and short arguments passed on the stack. */
#include "test.h"

NOINLINE int f(int a, int b, int c, int d, signed char e, short g) { return a + b + c + d + e * 1000 + g; }
int test_call(void) { return f(1, 2, 3, 4, -5, -300); }

// RUN: test_call = -5290
