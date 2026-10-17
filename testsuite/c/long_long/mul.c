/* 64-bit multiplication. */
#include "test.h"

NOINLINE long long f(long long a, long long b) { return a * b; }
int test_call(void) { long long r = f(100000LL, 300000LL); return (int)(r >> 32) * 100000 + (int)(r & 0xFFFF); }

// SKIP: test_call = 644032
