/* 64-bit unsigned comparison deciding on the high word. */
#include "test.h"

NOINLINE int f(unsigned long long a, unsigned long long b) { return a > b; }
int test_call(void) { return f(0x100000000ULL, 0xFFFFFFFFULL); }

// RUN: test_call = 1
