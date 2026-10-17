/* __builtin_clz. */
#include "test.h"

NOINLINE int f(unsigned x) { return __builtin_clz(x); }
int test_call(void) { return f(0x00010000u); }

// RUN: test_call = 15
