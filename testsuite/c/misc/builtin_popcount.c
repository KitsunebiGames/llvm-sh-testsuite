/* __builtin_popcount. */
#include "test.h"

NOINLINE int f(unsigned x) { return __builtin_popcount(x); }
int test_call(void) { return f(0xF0F0F0F1u); }

// RUN: test_call = 17
