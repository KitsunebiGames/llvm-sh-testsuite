/* 64-bit arithmetic right shift. */
#include "test.h"

NOINLINE long long f(long long a, int n) { return a >> n; }
int test_call(void) { return (int)f(-0x1000000000LL, 32); }

// RUN: test_call = -16
