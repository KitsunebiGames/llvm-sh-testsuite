/* 64-bit subtraction with borrow. */
#include "test.h"

NOINLINE long long f(long long a, long long b) { return a - b; }
int test_call(void) { long long r = f(0x100000000LL, 1LL); return (int)(r >> 32) * 10 + ((int)r == -1); }

// SKIP: test_call = 1
