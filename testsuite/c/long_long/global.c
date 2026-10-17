/* A 64-bit global variable. */
#include "test.h"

long long big = 0x123456789ALL;
NOINLINE long long f(void) { return big + 1; }
int test_call(void) { long long r = f(); return (int)(r >> 32) * 1000 + (int)(r & 0xFFF); }

// SKIP: test_call = 20203
