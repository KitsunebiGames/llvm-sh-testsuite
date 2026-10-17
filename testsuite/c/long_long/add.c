/* 64-bit addition with carry between the halves. */
#include "test.h"

NOINLINE long long f(long long a, long long b) { return a + b; }
int test_call(void) { long long r = f(0xFFFFFFFFLL, 1LL); return (int)(r >> 32) * 10 + (int)r; }

// SKIP: test_call = 10
