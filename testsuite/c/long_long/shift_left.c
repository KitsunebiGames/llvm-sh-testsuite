/* 64-bit left shift across the word boundary. */
#include "test.h"

NOINLINE unsigned long long f(unsigned long long a, int n) { return a << n; }
int test_call(void) { return (int)(f(3ULL, 33) >> 32); }

// SKIP: test_call = 6
