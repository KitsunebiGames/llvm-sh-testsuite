/* Const-qualified locals. */
#include "test.h"

NOINLINE int f(int x) { const int k = 7; const int y = x * k; return y + k; }
int test_call(void) { return f(6); }

// RUN: test_call = 49
