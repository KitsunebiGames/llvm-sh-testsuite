/* 64-bit signed comparison. */
#include "test.h"

NOINLINE int f(long long a, long long b) { return a < b; }
int test_lt(void) { return f(-1LL, 0x100000000LL); }
int test_ge(void) { return f(0x100000000LL, 5LL); }

// SKIP: test_lt = 1
// SKIP: test_ge = 0
