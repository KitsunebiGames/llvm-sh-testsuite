/* __builtin_ctz. */
#include "test.h"

NOINLINE int f(unsigned x) { return __builtin_ctz(x); }
int test_call(void) { return f(0x00010000u); }

// SKIP: test_call = 16
