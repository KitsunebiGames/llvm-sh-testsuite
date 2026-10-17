/* 64-bit negation. */
#include "test.h"

NOINLINE long long f(long long a) { return -a; }
int test_call(void) { long long r = f(1LL); return (int)(r >> 32) + (int)r; }

// RUN: test_call = -2
